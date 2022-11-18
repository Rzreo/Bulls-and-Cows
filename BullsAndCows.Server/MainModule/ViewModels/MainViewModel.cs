namespace MainModule.ViewModels
{
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.Utils;
    using BullsAndCows.Server.Net;
    using Prism.Commands;
    using Prism.Mvvm;
    using Prism.Services.Dialogs;
    using Reactive.Bindings;
    using System;
    using System.Collections.Generic;
    using System.IO.Packaging;
    using System.Linq;
    using System.Reactive.Disposables;
    using System.Windows;
    using System.Windows.Data;
    using System.Windows.Interop;
    using System.Windows.Markup;
    using static MainModule.ViewModels.MainViewModel;

    public class MainViewModel : BindableBase, IDisposable
    {
        public ReactiveCommand DoCSVLoad { get; set; } = new ReactiveCommand();

        public class Clients
        {
            public string ClientInfo { get; set; }
        }
        public ReactiveCollection<Clients> ConnectList { get; }

        public ReactiveCollection<BAC_ROOM_DATA> JoinableList { get; }

        public ReactiveCollection<BAC_ROOM_DATA> PlayingList { get; }

        private string _join;
        public string JoinableRooms
        {
            get { return _join; }
            set { SetProperty(ref _join, value); }
        }
        private string _connect;
        public string SuccessConnect
        {
            get { return _connect; }
            set { SetProperty(ref _connect, value); }
        }
        private DDSService dds;
        object _lock = new object();
        int RoomCount;
        string cid = "0-1";
        public MainViewModel(DDSService dDSService)
        {
            ConnectList = new ReactiveCollection<Clients>();
            BindingOperations.EnableCollectionSynchronization(ConnectList, _lock);

            JoinableList = new ReactiveCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(JoinableList, _lock);

            PlayingList = new ReactiveCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(PlayingList, _lock);

            dds = dDSService;
            RoomCount = 0;
            InitializeDDS();
        }

        public void InitializeDDS()
        {
            dds.RegisterEvent(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), data => ReceiveConnectMsg(data as BAC_CONNECT_INIT_MESSAGE));
            //dds.RegisterEvent(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE)+"123", data => ReceiveServerMsg(data as BAC_SERVER_CONNECT_MESSAGE,"123"));;
        }

        private void ReceiveClientMsg(BAC_CLIENT_CONNECT_MESSAGE data, string _clientid) // 메세지 수신 시
         {
            if (data is null) return;
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM) RoomMake(_clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_LIST) SendRoomList(_clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.ENTER_ROOM) EnterRoom(data, _clientid);
            
        }

        private void ReceiveServerMsg(BAC_SERVER_CONNECT_MESSAGE data, string _clientid) // 메세지 수신 시
        {
            if (data is null) return;
            else if (data.type == SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST) UpdateRoomList(data);
            else if (data.type == SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS) UpdateSuccessConnect(data);
        }

        private void UpdateSuccessConnect(BAC_SERVER_CONNECT_MESSAGE data)
        {
            SuccessConnect = data.msg;
        }
        private void UpdateRoomList(BAC_SERVER_CONNECT_MESSAGE data)
        {
            JoinableRooms = data.msg;
        }
        struct RoomListContainer//페이지 전송을 위한 구조체
        {
            public double pageNum { get; set; }
            public ReactiveCollection<BAC_ROOM_DATA> RoomList { get; set; }   
        }
        private void SendRoomList(string _clientid) //입장 가능한 방 정보 전송
        {
            RoomListContainer container = new RoomListContainer() { pageNum = Math.Ceiling((double)JoinableList.Count/8), RoomList = JoinableList };

            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(container);
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() => {
                dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientid,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST,
                        msg = ans
                    }
                ); 
            });
        }
        private void RoomMake(string _clientid) //방 생성
        {
            BAC_ROOM_DATA data = new BAC_ROOM_DATA() { RoomID = (uint)RoomCount++ };
            JoinableList.Add(data);
            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(data);
            Console.WriteLine(ans);
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _clientid,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.CREATE_ROOM_SUCCESS,
                        msg = ans
                    }
                ); ;
            });
        }
        private void ReceiveConnectMsg(BAC_CONNECT_INIT_MESSAGE data) //연결 메세지 수신 시
        {
            if (data is null) return;
            Clients _client = new Clients() { ClientInfo = data.CLIENT_ID };
            ConnectList.Add(_client);
            SendJoinableList(data.CLIENT_ID);
        }

        void SendJoinableList(string clientId) //연결응답 보내기
        {
            cid = clientId;
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() => {
              dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + clientId,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
                        msg = "connect success"
                    }
                );
                //dds.RegisterEvent(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + clientId, data => ReceiveClientMsg(data as BAC_CLIENT_CONNECT_MESSAGE, clientId));
            });

        }

        private void EnterRoom(BAC_CLIENT_CONNECT_MESSAGE data, string clientId)
        {
            if (Int32.TryParse(data.msg, out int roolId))
            {
                bool exist = false;
                BAC_ROOM_DATA playRoom = new  BAC_ROOM_DATA();
                foreach (BAC_ROOM_DATA room in JoinableList)
                {
                    if(room.RoomID== roolId) 
                    { 
                        playRoom= room;
                        exist = true;
                        break;
                    }
                }
                if (exist)
                {
                    PlayingList.Add(playRoom);
                    JoinableList.Remove(playRoom);
                    return;//들어갔다고 답변 전송
                }
               
            }
            return;//못들어갔다고 답변전송
        }

        private DelegateCommand msgsend;
        public DelegateCommand MsgSend =>
            msgsend ?? (msgsend = new DelegateCommand(ExecuteMsgSend));
        void ExecuteMsgSend()
        {
            dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE),
                new BAC_CONNECT_INIT_MESSAGE()
                {
                    CLIENT_ID = "1-0"
                });
        }

        private DelegateCommand roomsend;
        public DelegateCommand RoomSend =>
            roomsend ?? (roomsend = new DelegateCommand(ExecuteRoomSend));

        void ExecuteRoomSend()
        {
            dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + cid,
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM,
                    msg = "please make room"
                });
        }

        private DelegateCommand showroom;
        public DelegateCommand ListSend =>
            showroom ?? (showroom = new DelegateCommand(ExecuteListSend));

        void ExecuteListSend()
        {
            dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + cid,
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_LIST,
                    msg = "please give room"
                });
        }
        protected CompositeDisposable disposables { get; } = new CompositeDisposable();

        private bool disposedValue;

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    this.disposables.Dispose();
                }
                disposedValue = true;
            }
        }
    }
}

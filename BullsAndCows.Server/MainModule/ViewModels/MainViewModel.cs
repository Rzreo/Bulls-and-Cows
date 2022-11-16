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

        public ReactiveCollection<BAS_ROOM_DATA> JoinableList { get; }

        public ReactiveCollection<BAS_ROOM_DATA> PlayingList { get; }

        private string _join;
        public string JoinableRooms
        {
            get { return _join; }
            set { SetProperty(ref _join, value); }
        }

        private DDSService dds;
        object _lock = new object();
        int RoomCount;
        public MainViewModel(DDSService dDSService)
        {
            ConnectList = new ReactiveCollection<Clients>();
            BindingOperations.EnableCollectionSynchronization(ConnectList, _lock);

            JoinableList = new ReactiveCollection<BAS_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(JoinableList, _lock);

            PlayingList = new ReactiveCollection<BAS_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(PlayingList, _lock);

            dds = dDSService;
            RoomCount = 0;
            InitializeDDS();
        }

        public void InitializeDDS()
        {
            dds.RegisterEvent(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), data => ReceiveConnectMsg(data as BAC_CONNECT_INIT_MESSAGE));
            //dds.RegisterEvent(typeof(BAS_ROOM_DATA), nameof(BAS_ROOM_DATA), data => ReceiveRoomMakeMsg(data as BAS_ROOM_DATA));
            dds.RegisterEvent(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE), () => { });
        }

        private void ReceiveMsg(BAC_CONNECT_MESSAGE data, string _clientid) // 메세지 수신 시
        {
            if (data is null) return;
            if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM) RoomMake(_clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.GIVE_ROOM_LIST) SendRoomList(_clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST) UpdateRoomList(data);
            
        }

        private void UpdateRoomList(BAC_CONNECT_MESSAGE data)
        {
            JoinableRooms = data.msg;
        }
        private void SendRoomList(string _clientid) //입장 가능한 방 정보 전송
        {
            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(JoinableList);
            Application.Current.Dispatcher.BeginInvoke(() => {
                dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + _clientid,
                    new BAC_CONNECT_MESSAGE
                    {
                        type = CLIENT_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST,
                        msg = ans
                    }
                ); 
            });
        }
        private void RoomMake(string _clientid) //방 생성
        {
            BAS_ROOM_DATA data = new BAS_ROOM_DATA() { RoomID = (uint)RoomCount++ };
            JoinableList.Add(data);
            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(data);
            Console.WriteLine(ans);
            Application.Current.Dispatcher.Invoke(() =>
            {
                dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + _clientid,
                    new BAC_CONNECT_MESSAGE
                    {
                        type = CLIENT_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
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
            Application.Current.Dispatcher.BeginInvoke(() => {
                dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) ,
                    new BAC_CONNECT_MESSAGE
                    {
                        type = CLIENT_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
                        msg = "connect success"
                    }
                );
                dds.RegisterEvent(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + clientId, data => ReceiveMsg(data as BAC_CONNECT_MESSAGE, clientId));
            });

        }

        private DelegateCommand msgsend;
        public DelegateCommand MsgSend =>
            msgsend ?? (msgsend = new DelegateCommand(ExecuteMsgSend));
        void ExecuteMsgSend()
        {
            dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE),
                new BAC_CONNECT_INIT_MESSAGE()
                {
                    CLIENT_ID = "123"
                });
        }

        private DelegateCommand roomsend;
        public DelegateCommand RoomSend =>
            roomsend ?? (roomsend = new DelegateCommand(ExecuteRoomSend));

        void ExecuteRoomSend()
        {
            dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + "123",
                new BAC_CONNECT_MESSAGE()
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
            dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + "123",
                new BAC_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.GIVE_ROOM_LIST,
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

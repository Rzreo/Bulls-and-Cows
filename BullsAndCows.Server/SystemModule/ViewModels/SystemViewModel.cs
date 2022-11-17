namespace SystemModule.ViewModels
{
    using BullsAndCows.Server.Net;
    using BullsAndCows.Infrastructure;
    using Prism.Commands;
    using Prism.Mvvm;
    using Reactive.Bindings;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Windows.Forms;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.Utils;
    using System.Reactive.Disposables;
    using System.Windows.Data;
    using ICSharpCode.AvalonEdit.Document;

    public class SystemViewModel : BindableBase, IDisposable
    {
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
        /// <summary>
        /// //
        /// </summary>
        public ReactiveCommand DoCSVLoad { get; set; } = new ReactiveCommand();
        public ReactiveCollection<MSGcontainer> RecvMessages { get; }

        public ReactiveCollection<MSGcontainer> SendMessages { get; }

        public ReactiveCommand SendClearFunction { get; set; } = new ReactiveCommand();
        public ReactiveCommand RecvClearFunction { get; set; } = new ReactiveCommand();

        public ReactiveProperty<MSGcontainer> SelectedLogLeft { get; set; } = new ReactiveProperty<MSGcontainer>();
        public ReactiveProperty<MSGcontainer> SelectedLogRight { get; set; } = new ReactiveProperty<MSGcontainer>();
        public ReactiveProperty<TextDocument> LogDocumentLeft { get; } = new ReactiveProperty<TextDocument>();

        public ReactiveProperty<TextDocument> LogDocumentRight { get; } = new ReactiveProperty<TextDocument>();

        private DDSService dds;
        object _lock = new object();
        int RoomCount;
        public SystemViewModel(DDSService dds)
        {
            ConnectList = new ReactiveCollection<Clients>();
            BindingOperations.EnableCollectionSynchronization(ConnectList, _lock);

            JoinableList = new ReactiveCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(JoinableList, _lock);

            PlayingList = new ReactiveCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(PlayingList, _lock);

            LogDocumentLeft.Value = new TextDocument();
            LogDocumentLeft.Value.UndoStack.SizeLimit = 0;

            LogDocumentRight.Value = new TextDocument();
            LogDocumentRight.Value.UndoStack.SizeLimit = 0;


            //unitTest.SelectedItem.Subscribe((data) =>
            //{
            //    LogDocument.Value.Text = string.Empty;

            //    if (data != null)
            //        LogDocument.Value.Text = data.Values;
            //}).AddTo(disposables);


            SendClearFunction.Subscribe(() => {
                dds.SendClearEvent();
            });
            RecvClearFunction.Subscribe(() => {
                dds.RecvClearEvent();
            });
            SelectedLogLeft.Subscribe(item =>
            {
                if (item is null) return;
                LogDocumentLeft.Value.Text = string.Empty;

                if (item != null)
                {
                    OpenContainer(item, true);
                }
            });

            SelectedLogRight.Subscribe(item =>
            {
                if (item is null) return;
                LogDocumentRight.Value.Text = string.Empty;

                if (item != null)
                {
                    OpenContainer(item, false);
                }

            });

            this.dds = dds;
            RoomCount = 0;
            RecvMessages = dds.RCVmessages;
            SendMessages = dds.SNDmessages;
            InitializeDDS();
        }

        public void OpenContainer(MSGcontainer container, bool left)
        {
            if (container.data.GetType() == typeof(BAC_CONNECT_INIT_MESSAGE))
            {
                BAC_CONNECT_INIT_MESSAGE init = (BAC_CONNECT_INIT_MESSAGE)container.data;
                if(left) LogDocumentLeft.Value.Text = $"Clinet_id: {init.CLIENT_ID}";
                else LogDocumentRight.Value.Text = $"Clinet_id: {init.CLIENT_ID}";
            }
            else if (container.data.GetType() == typeof(BAC_CLIENT_CONNECT_MESSAGE))
            {
                BAC_CLIENT_CONNECT_MESSAGE init = (BAC_CLIENT_CONNECT_MESSAGE)container.data;
                if (left) LogDocumentLeft.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
                else LogDocumentRight.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
            }
            else if (container.data.GetType() == typeof(BAC_SERVER_CONNECT_MESSAGE))
            {
                BAC_SERVER_CONNECT_MESSAGE init = (BAC_SERVER_CONNECT_MESSAGE)container.data;
                if (left) LogDocumentLeft.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
                else LogDocumentRight.Value.Text = $"Type: {init.type}\nMsg: {init.msg.Replace(',', '\n')}";
            }
        }
        public void InitializeDDS()
        {
            dds.RegisterEvent(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), data => ReceiveConnectMsg(data as BAC_CONNECT_INIT_MESSAGE));
            //dds.RegisterEvent(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + "1-0", data => ReceiveServerMsg(data as BAC_SERVER_CONNECT_MESSAGE, "123")); ;
        }

        private void ReceiveClientMsg(BAC_CLIENT_CONNECT_MESSAGE data, string _clientid) // 메세지 수신 시
        {
            if (data is null) return;
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM) RoomMake(_clientid);
            else if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.GIVE_ROOM_LIST) SendRoomList(data, _clientid);
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
            public List<BAC_ROOM_DATA> RoomList { get; set; }
        }
        private void SendRoomList(BAC_CLIENT_CONNECT_MESSAGE data, string _clientid) //입장 가능한 방 정보 전송
        {
            if (!Int32.TryParse(data.msg, out int pnum)) return;
            if (pnum > Math.Ceiling((double)JoinableList.Count / 8)) return;
            List<BAC_ROOM_DATA> copy;
            if (pnum * 8 > JoinableList.Count) copy = JoinableList.ToList().GetRange((pnum - 1) * 8, JoinableList.Count - (pnum - 1) * 8);
            else copy = JoinableList.ToList().GetRange((pnum - 1) * 8, 8);
            RoomListContainer container = new RoomListContainer() { pageNum = Math.Ceiling((double)JoinableList.Count / 8), RoomList = copy };
            System.Diagnostics.Debug.WriteLine(container.RoomList.Count);

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
            bool canConnect = true;
            foreach (Clients c in ConnectList)
            {
                if (c.ClientInfo.Equals(data.CLIENT_ID)) canConnect = false;
            }
            if (canConnect)
            {
                Clients _client = new Clients() { ClientInfo = data.CLIENT_ID };
                ConnectList.Add(_client);
                SendJoinableList(data.CLIENT_ID);
            }
        }

        void SendJoinableList(string clientId) //연결응답 보내기
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() => {
                dds.Write(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + clientId,
                    new BAC_SERVER_CONNECT_MESSAGE
                    {
                        type = SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
                        msg = "connect success"
                    }
                );
                dds.RegisterEvent(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + clientId, data => ReceiveClientMsg(data as BAC_CLIENT_CONNECT_MESSAGE, clientId));
            });

        }

        private void EnterRoom(BAC_CLIENT_CONNECT_MESSAGE data, string clientId)
        {
            if (Int32.TryParse(data.msg, out int roolId))
            {
                bool exist = false;
                BAC_ROOM_DATA playRoom = new BAC_ROOM_DATA();
                foreach (BAC_ROOM_DATA room in JoinableList)
                {
                    if (room.RoomID == roolId)
                    {
                        playRoom = room;
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
            dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + "1-0",
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
            dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + "1-0",
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.GIVE_ROOM_LIST,
                    msg = "1"
                });
        }










        /// <summary>
        /// ///////////////////////////////////////
        /// </summary>
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


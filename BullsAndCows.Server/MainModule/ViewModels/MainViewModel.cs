namespace MainModule.ViewModels
{
    using BullsAndCows.Infrastructure.Net;
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
        }

        private void ReceiveMsg(BAC_CONNECT_MESSAGE data, string _clientid) // 메세지 수신 시
        {
            if (data is null) return;
            if (data.type == CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM) RoomMake(_clientid);
             
            
        }

        private void RoomMake(string _clientid) //방 생성
        {
            BAS_ROOM_DATA data = new BAS_ROOM_DATA() { room_id = (uint)++RoomCount };
            JoinableList.Add(data);
            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(data);
            Application.Current.Dispatcher.Invoke(() => {
                dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + _clientid,
                    new BAC_CONNECT_MESSAGE
                    {
                        type = CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM,
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
            string ans = Newtonsoft.Json.JsonConvert.SerializeObject(JoinableList);
            Application.Current.Dispatcher.Invoke(() => {
                dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + clientId,
                    new BAC_CONNECT_MESSAGE
                    {
                        type = CLIENT_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
                        msg = ans
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

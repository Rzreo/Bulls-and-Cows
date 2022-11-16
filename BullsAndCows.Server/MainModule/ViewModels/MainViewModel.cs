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

    public class MainViewModel : BindableBase, IDisposable
    {
        public ReactiveCommand DoCSVLoad { get; set; } = new ReactiveCommand();

        bool[] array = new bool[8];
        struct BAS_ROOM_DATA { public int id; }
        public class Room
        {
            public string infomsg { get; set; }
        }

        public ReactiveCollection<Room> RoomList { get; }
        public ReactiveProperty<string> msg { get; set; } = new ReactiveProperty<string>();
        private DDSService dds;
        object _lock = new object();
        public MainViewModel(DDSService dDSService)
        {
            RoomList = new ReactiveCollection<Room>();
            BindingOperations.EnableCollectionSynchronization(RoomList, _lock);
            dds = dDSService;
            for (int i = 0; i < 8; i++) array[i] = true;
            InitializeDDS();
        }

        public void InitializeDDS()
        {
            dds.RegisterEvent(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), data => ReceiveTestMsg(data as BAC_CONNECT_INIT_MESSAGE));
        }

        private void ReceiveTestMsg(BAC_CONNECT_INIT_MESSAGE data)
        {
            if (data is null) return;
            Room room = new Room() { infomsg = data.CLIENT_ID };
            RoomList.Add(room);
            SendAnswer(data);
        }
        private DelegateCommand msgsend;
        public DelegateCommand MsgSend =>
            msgsend ?? (msgsend = new DelegateCommand(ExecuteMsgSend));

        void SendAnswer(BAC_CONNECT_INIT_MESSAGE data)
        {
            Application.Current.Dispatcher.Invoke(() => {
                var var = new List<BAS_ROOM_DATA>();
                for (int i = 0; i < 8; i++)
                {
                    if (array[i]) var.Add(new BAS_ROOM_DATA() { id = i });
                }
                string ans = Newtonsoft.Json.JsonConvert.SerializeObject(var);
                dds.Write(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + data.CLIENT_ID,
                    new BAC_CONNECT_MESSAGE
                    {
                        type = CLIENT_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS,
                        msg = ans
                    }
                );
            });

        }
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

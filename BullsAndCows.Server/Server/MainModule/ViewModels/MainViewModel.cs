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
            InitializeDDS();
        }

        public void InitializeDDS()
        {
            dds.RegisterEvent(typeof(BAC_CREATE_ROOM), nameof(BAC_CREATE_ROOM), data => ReceiveTestMsg(data as BAC_CREATE_ROOM));
        }

        private void ReceiveTestMsg(BAC_CREATE_ROOM data)
        {
            if (data is null) return;
            Room room = new Room() { infomsg = $"RoomId: {data.ROOM_ID} / ClientId: {data.CLIENT_ID}" };
            RoomList.Add(room);
            SendAnswer(data);
        }
        private DelegateCommand msgsend;
        public DelegateCommand MsgSend =>
            msgsend ?? (msgsend = new DelegateCommand(ExecuteMsgSend));

        void SendAnswer(BAC_CREATE_ROOM data)
        {
            dds.Write(typeof(Message), nameof(Message) + data.CLIENT_ID,
                new Message
                {
                    msg = "hello"
                }
                );
        }
        void ExecuteMsgSend()
        {
            dds.Write(typeof(BAC_CREATE_ROOM), nameof(BAC_CREATE_ROOM),
                new BAC_CREATE_ROOM()
                {
                    ROOM_ID = "321",
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

namespace BullsAndCows.Client.Views.ViewModels
{
    using System;
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using Newtonsoft.Json.Linq;
    using Prism.Commands;
    using Reactive.Bindings;
    using System.Collections.ObjectModel;
    using System.IO;
    using System.Windows.Controls;
    using System.Windows.Data;
    using System.Windows.Input;
    using System.Windows.Interop;
    using System.Windows.Threading;
    using System.Linq;
    using Newtonsoft.Json;
    using System.Text;
    using System.Windows.Controls.Primitives;
    using System.Threading;
    using System.Threading.Tasks;
    using System.Windows;
    using BullsAndCows.Infrastructure.ClientServices;

    class LoginMainViewModel : ViewModelBase
    {
        IDDSService _dds;
        IServerConnectingService _connect;
        object _lock = new object();
        int cnt = 0;
        public IConfigService Config { get; private set; }
        public ObservableCollection<BAC_ROOM_DATA> RoomDatas { get; private set; }
        public ReactiveProperty<int> CurrentPageNumber { get; private set; } = new ReactiveProperty<int>() { Value=0 };
        public ReactiveProperty<int> LastPageNumber { get; private set; } = new ReactiveProperty<int>() { Value=0 };
        public LoginMainViewModel(IDDSService dds, IConfigService config, IServerConnectingService connect)
        {
            this._dds = dds;
            this.Config = config;
            this._connect = connect;

            RoomDatas = new ObservableCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(RoomDatas, _lock);

            _connect.ReceiveServerMessage += ReceiveMessage;
            _connect.StartConnect();
        }

        void ReceiveMessage(object s)
        {
            BAC_SERVER_CONNECT_MESSAGE msg = s as BAC_SERVER_CONNECT_MESSAGE;

            switch(msg.type)
            {
                case SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS: OnConnectSuccess(msg); break;
                case SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST: OnSendRoomList(msg); break;
                case SERVER_CONNECT_MESSAGE_TYPE.CREATE_ROOM_SUCCESS: OnCreateRoomSuccess(msg); break;
            }
        }

        void OnConnectSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            if (Config.IsConnected.Value == true) return;

            System.Diagnostics.Debug.WriteLine(cnt);
            Config.IsConnected.Value = true;
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                RequestRoomList(CurrentPageNumber.Value = 1);
            });    
        }
        void OnSendRoomList(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                JObject obj = JObject.Parse(msg.msg);
                LastPageNumber.Value = obj["pageNum"].Value<int>();
                foreach (var data in obj["RoomList"] as JArray)
                {
                    BAC_ROOM_DATA roomData = JsonConvert.DeserializeObject<BAC_ROOM_DATA>(data.ToString());
                    RoomDatas.Add(roomData);
                }

                _RequestPrevRoomListCommand.RaiseCanExecuteChanged();
                _RequestNextRoomListCommand.RaiseCanExecuteChanged();
            });
        }
        void OnCreateRoomSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + Config.ClientID(),
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.ENTER_ROOM,
                    msg = msg.msg
                });
            });
        }

        #region CreateRoom
        DelegateCommand _CreateRoomCommand;
        public DelegateCommand CreateRoomCommand
        {
            get
            {
                if (_CreateRoomCommand == null)
                {
                    _CreateRoomCommand = new DelegateCommand(CreateRoom, () => { return true; });
                }
                return _CreateRoomCommand;
            }
        }
        void CreateRoom()
        {
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + Config.ClientID(),
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM
                });
            RequestRoomList(CurrentPageNumber.Value);
            Config.IsConnected.Value = true;
        }
        #endregion

        #region RequestRoomList
        DelegateCommand _RequestNextRoomListCommand, _RequestPrevRoomListCommand;
        public DelegateCommand RequestNextRoomListCommand
        {
            get
            {
                var k = new DelegateCommand(() => {  });
                if (_RequestNextRoomListCommand == null)
                {
                    _RequestNextRoomListCommand = new DelegateCommand(()=>RequestRoomList(CurrentPageNumber.Value += 1), () => { return CurrentPageNumber.Value < LastPageNumber.Value; });
                }
                return _RequestNextRoomListCommand;
            }
        }
        public DelegateCommand RequestPrevRoomListCommand
        {
            get
            {
                var k = new DelegateCommand(() => { });
                if (_RequestPrevRoomListCommand == null)
                {
                    _RequestPrevRoomListCommand = new DelegateCommand(() => RequestRoomList(CurrentPageNumber.Value -= 1), () => { return CurrentPageNumber.Value > 1; });
                }
                return _RequestPrevRoomListCommand;
            }
        }
        void RequestRoomList(int nPage)
        {
            RoomDatas.Clear();
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + Config.ClientID(),
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.GIVE_ROOM_LIST,
                    msg = nPage.ToString()
                });
        }
        #endregion

        #region EnterRoom
        DelegateCommand<MouseButtonEventArgs> _EnterRoomCommand;
        public DelegateCommand<MouseButtonEventArgs> EnterRoomCommand
        {
            get
            {
                if (_EnterRoomCommand == null)
                {
                    _EnterRoomCommand = new DelegateCommand<MouseButtonEventArgs>(EnterRoom, (_) => { return true; });
                }
                return _EnterRoomCommand;
            }
        }
        void EnterRoom(MouseButtonEventArgs args)
        {
            Selector listview = args.Source as Selector;
            var item = (BAC_ROOM_DATA)listview.SelectedItem;
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + Config.ClientID(),
                new BAC_CLIENT_CONNECT_MESSAGE()
                {
                    type = CLIENT_CONNECT_MESSAGE_TYPE.ENTER_ROOM,
                    msg = item.RoomID.ToString()
                });
        }
        #endregion
    }
}

﻿namespace BullsAndCows.Client.Views.ViewModels
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
    using System.Windows.Controls.Primitives;
    using BullsAndCows.Infrastructure.ClientServices;
    using Prism.Services.Dialogs;
    using System.Runtime.InteropServices;
    using BullsAndCows.Client.Dialogs.Views;

    class LoginMainViewModel : ViewModelBase
    {
        IServerConnectingService _connect;
        IGameManageService _game;
        IDialogService _dialog;
        object _lock = new object();
        public IConfigService Config { get; private set; }
        public ObservableCollection<BAC_ROOM_DATA> RoomDatas { get; private set; }
        public ReactiveProperty<int> CurrentPageNumber { get; private set; } = new ReactiveProperty<int>() { Value=0 };
        public ReactiveProperty<int> LastPageNumber { get; private set; } = new ReactiveProperty<int>() { Value=0 };
        public LoginMainViewModel(IDialogService dialog, IServerConnectingService connect, IGameManageService game, IConfigService config)
        {
            this._connect = connect;
            this._game = game;
            this._dialog = dialog;
            this.Config = config;

            RoomDatas = new ObservableCollection<BAC_ROOM_DATA>();
            BindingOperations.EnableCollectionSynchronization(RoomDatas, _lock);

            _connect.ReceiveServerMessage += ReceiveMessage;
            _connect.StartConnect();
        }

        void ReceiveMessage(object s)
        {
            if(s is BAC_SERVER_CONNECT_MESSAGE msg)
            {
                switch (msg.type)
                {
                    case SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS: OnConnectSuccess(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_LIST: OnSendRoomList(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.CREATE_ROOM_SUCCESS: OnCreateRoomSuccess(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.ENTER_ROOM_SUCCESS: OnEnterRoomSuccess(msg); break;
                }
            }
        }

        void OnConnectSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            if (Config.IsConnected.Value == true) return;

            Config.IsConnected.Value = true;
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                _connect.RequestRoomList(CurrentPageNumber.Value = 1);
            });    
        }
        void OnSendRoomList(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                JObject obj = JObject.Parse(msg.msg);
                LastPageNumber.Value = obj["pageNum"].Value<int>();

                RoomDatas.Clear();
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
                BAC_ROOM_DATA room_data = JsonConvert.DeserializeObject<BAC_ROOM_DATA>(msg.msg);
                _connect.EnterRoom(room_data.RoomID);
            });
        }
        void OnEnterRoomSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                _game.GoToWaitting();
            });
        }

        #region CreateRoom
        DelegateCommand? _CreateRoomCommand;
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
            _dialog.ShowDialog(nameof(CreateRoomDialog), new DialogParameters($"message={"ㅋㅋㅋㅋ"}"), r =>
            {
                if (r.Result == ButtonResult.OK)
                {
                    _connect.CreateRoom(r.Parameters.GetValue<uint>("Capacity"));
                    _connect.RequestRoomList(CurrentPageNumber.Value);
                }
            }, "DialogWindow");
        }
        #endregion

        #region RequestRoomList
        DelegateCommand? _RequestNextRoomListCommand, _RequestPrevRoomListCommand;
        public DelegateCommand RequestNextRoomListCommand
        {
            get
            {
                if (_RequestNextRoomListCommand == null)
                {
                    _RequestNextRoomListCommand = new DelegateCommand(()=> _connect.RequestRoomList(CurrentPageNumber.Value += 1), () => { return CurrentPageNumber.Value < LastPageNumber.Value; });
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
                    _RequestPrevRoomListCommand = new DelegateCommand(() => _connect.RequestRoomList(CurrentPageNumber.Value -= 1), () => { return CurrentPageNumber.Value > 1; });
                }
                return _RequestPrevRoomListCommand;
            }
        }
        #endregion

        #region EnterRoom
        DelegateCommand<MouseButtonEventArgs>? _EnterRoomCommand;
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
            if(args.Source is Selector selector)
            {
                var item = (BAC_ROOM_DATA)selector.SelectedItem;
                _connect.EnterRoom(item.RoomID);
            }
        }
        #endregion
    }
}

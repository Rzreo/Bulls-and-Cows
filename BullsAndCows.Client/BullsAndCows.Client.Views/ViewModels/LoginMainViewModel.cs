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
    using System.Windows.Controls.Primitives;
    using BullsAndCows.Infrastructure.ClientServices;
    using Prism.Services.Dialogs;
    using System.Runtime.InteropServices;
    using BullsAndCows.Client.Dialogs.Views;
    using BullsAndCows.Client.MainModule;

    class LoginMainViewModel : ViewModelBase
    {
        IServerConnectingService _connect;
        IDialogService _dialog;
        public IConfigService Config { get; private set; }
        public LobbyStateModel Model { get; private set; }
        public LoginMainViewModel(LobbyStateModel model, IDialogService dialog, IServerConnectingService connect, IConfigService config)
        {
            this._connect = connect;
            this._dialog = dialog;
            this.Config = config;
            this.Model = model;

            model.ReceivedRoomList += OnReceiveRoomList;
        }

        #region Receive Message
        void OnReceiveRoomList(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                _RequestPrevRoomListCommand?.RaiseCanExecuteChanged();
                _RequestNextRoomListCommand?.RaiseCanExecuteChanged();
            });
        }
        #endregion

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
                    _connect.RequestRoomList(Model.CurrentPageNumber.Value);
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
                    _RequestNextRoomListCommand = new DelegateCommand(()=> _connect.RequestRoomList(Model.CurrentPageNumber.Value += 1), () => { return Model.CurrentPageNumber.Value < Model.LastPageNumber.Value; });
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
                    _RequestPrevRoomListCommand = new DelegateCommand(() => _connect.RequestRoomList(Model.CurrentPageNumber.Value -= 1), () => { return Model.CurrentPageNumber.Value > 1; });
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
            if(args.Source is Selector selector && selector.SelectedItem != null)
            {
                var item = (BAC_ROOM_DATA)selector.SelectedItem;
                _connect.EnterRoom(item.RoomID);
            }
        }
        #endregion
    }
}

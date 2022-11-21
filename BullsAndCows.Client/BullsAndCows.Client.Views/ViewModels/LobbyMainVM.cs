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

    class LobbyMainVM : ViewModelBase
    {
        IDialogService _dialog;
        public IServerConnectingService Connect { get; private set; }
        public LobbyStateModel Model { get; private set; }
        public LobbyMainVM(LobbyStateModel model, IDialogService dialog, IServerConnectingService connect)
        {
            this._dialog = dialog;
            this.Connect = connect;
            this.Model = model;

            model.ReceivedRoomList += OnReceiveRoomList;
            model.ConnectedChanged += (_) => CreateRoomCommand.RaiseCanExecuteChanged();
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
                    _CreateRoomCommand = new DelegateCommand(CreateRoom, () => { return Connect.IsConnected.Value; });
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
                    Connect.CreateRoom(r.Parameters.GetValue<uint>("Capacity"));
                    Connect.RequestRoomList(Model.CurrentPageNumber.Value);
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
                    _RequestNextRoomListCommand = new DelegateCommand(()=> Connect.RequestRoomList(Model.CurrentPageNumber.Value += 1), () => { return Model.CurrentPageNumber.Value < Model.LastPageNumber.Value; });
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
                    _RequestPrevRoomListCommand = new DelegateCommand(() => Connect.RequestRoomList(Model.CurrentPageNumber.Value -= 1), () => { return Model.CurrentPageNumber.Value > 1; });
                }
                return _RequestPrevRoomListCommand;
            }
        }
        #endregion
    }
}

using BullsAndCows.Client.MainModule;
using BullsAndCows.Infrastructure;
using BullsAndCows.Infrastructure.BaseClass;
using BullsAndCows.Infrastructure.ClientServices;
using BullsAndCows.Infrastructure.Utils;
using Prism.Commands;
using Prism.Services.Dialogs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls.Primitives;
using System.Windows.Input;

namespace BullsAndCows.Client.Views.ViewModels
{
    public class RoomListVM : ViewModelBase
    {
        public IServerConnectingService Connect { get; private set; }
        public LobbyStateModel Model { get; private set; }
        public RoomListVM(LobbyStateModel model, IServerConnectingService connect)
        {
            this.Connect = connect;
            this.Model = model;

            model.ReceivedRoomList += OnReceiveRoomList;
        }

        #region EnterRoom
        DelegateCommand<MouseButtonEventArgs>? _EnterRoomCommand;
        public DelegateCommand<MouseButtonEventArgs> EnterRoomCommand
        {
            get
            {
                if (_EnterRoomCommand == null)
                {
                    _EnterRoomCommand = new DelegateCommand<MouseButtonEventArgs>(EnterRoom, (_) => { return Connect.IsConnected.Value; });
                }
                return _EnterRoomCommand;
            }
        }
        void EnterRoom(MouseButtonEventArgs args)
        {
            if (args.Source is Selector selector && selector.SelectedItem != null)
            {
                var item = (BAC_ROOM_DATA)selector.SelectedItem;
                Connect.EnterRoom(item.RoomID);
            }
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
                    _RequestNextRoomListCommand = new DelegateCommand(() => Connect.RequestRoomList(Model.CurrentPageNumber.Value += 1), () => { return Model.CurrentPageNumber.Value < Model.LastPageNumber.Value; });
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

        void OnReceiveRoomList(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                _RequestPrevRoomListCommand?.RaiseCanExecuteChanged();
                _RequestNextRoomListCommand?.RaiseCanExecuteChanged();
            });
        }
    }
}

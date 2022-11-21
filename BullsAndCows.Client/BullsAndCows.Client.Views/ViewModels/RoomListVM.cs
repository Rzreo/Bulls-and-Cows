using BullsAndCows.Client.MainModule;
using BullsAndCows.Infrastructure;
using BullsAndCows.Infrastructure.BaseClass;
using BullsAndCows.Infrastructure.ClientServices;
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
    }
}

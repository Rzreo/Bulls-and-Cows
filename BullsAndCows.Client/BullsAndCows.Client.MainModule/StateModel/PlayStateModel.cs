using BullsAndCows.Infrastructure.ClientServices;
using BullsAndCows.Infrastructure.OperationManagement;
using Prism.Services.Dialogs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.MainModule
{
    internal class PlayStateModel : StateModel
    {
        IServerConnectingService _connect;
        IGameManageService _game;
        IConfigService _config;
        public PlayStateModel(IDialogService dialog, IServerConnectingService connect, IGameManageService game, IConfigService config)
        {
            this._config = config;
            this._connect = connect;
            this._game = game;

            EnterState();
        }

        #region StateModel
        protected override void EnterState()
        {
            bValidState = true;
            _connect.ReceiveServerMessage += ReceiveMessage;
        }
        protected override void ExitState()
        {
            _connect.ReceiveServerMessage -= ReceiveMessage;
            bValidState = false;
        }
        public override bool bValidState { get; protected set; }
        #endregion

        void ReceiveMessage(object s)
        {
            if (s is BAC_SERVER_CONNECT_MESSAGE msg)
            {
                switch (msg.type)
                {
                    //case SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_DATA: OnReceiveRoomData(msg); break;
                }
            }
        }
    }
}

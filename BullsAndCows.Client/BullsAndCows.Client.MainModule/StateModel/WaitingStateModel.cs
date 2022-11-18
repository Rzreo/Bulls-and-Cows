using BullsAndCows.Infrastructure.ClientServices;
using BullsAndCows.Infrastructure.OperationManagement;
using BullsAndCows.Infrastructure;
using Prism.Services.Dialogs;
using Reactive.Bindings;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using BullsAndCows.Infrastructure.Utils;
using Newtonsoft.Json;
using System.Windows.Markup;

namespace BullsAndCows.Client.MainModule
{
    public class WaitingStateModel : StateModel
    {
        IServerConnectingService _connect;
        IGameManageService _game;
        IConfigService _config;
        object _lock = new object();
        public ReactiveProperty<BAC_ROOM_DATA> RoomData { get; private set; } = new ReactiveProperty<BAC_ROOM_DATA>();
        public WaitingStateModel(IDialogService dialog, IServerConnectingService connect, IGameManageService game, IConfigService config)
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
            var t = new Thread(UpdateRoomData) { IsBackground = true };
            t.Start();
        }
        protected override void ExitState()
        {
            _connect.ReceiveServerMessage -= ReceiveMessage;
            bValidState = false;
        }
        public override bool bValidState { get; protected set; }
        #endregion

        void UpdateRoomData()
        {
            while (bValidState)
            {
                _connect.RequestRoomData(0);
                Thread.Sleep(500);
            }
        }
        void ReceiveMessage(object s)
        {
            if (s is BAC_SERVER_CONNECT_MESSAGE msg)
            {
                switch (msg.type)
                {
                    case SERVER_CONNECT_MESSAGE_TYPE.SEND_ROOM_DATA: OnReceiveRoomData(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.REQUEST_GAME_START: OnRequestedGameStart(msg); break;
                }
            }
        }
        void OnReceiveRoomData(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            RoomData.Value = JsonConvert.DeserializeObject<BAC_ROOM_DATA>(msg.msg);
        }
        void OnRequestedGameStart(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            ExitState();
            _game.GoToPlaying();           
        }
    }
}

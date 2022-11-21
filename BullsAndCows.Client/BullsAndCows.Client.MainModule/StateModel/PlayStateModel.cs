using BullsAndCows.Infrastructure;
using BullsAndCows.Infrastructure.ClientServices;
using BullsAndCows.Infrastructure.OperationManagement;
using BullsAndCows.Infrastructure.Utils;
using Newtonsoft.Json;
using Prism.Services.Dialogs;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace BullsAndCows.Client.MainModule
{
    public class PlayStateModel : StateModel
    {
        IConfigService _config;
        IServerConnectingService _connect;
        IGameManageService _game;
        object _lock = new object();
        public ObservableCollection<BAC_GAME_OUTPUT_DATA> GameLogs { get; private set; }
        public BAC_GAME_RESULT_DATA RESULT { get; private set; }
        public bool bWin { get; private set; } = false;
        public PlayStateModel( IServerConnectingService connect, IGameManageService game, IConfigService config)
        {
            this._config = config;
            this._connect = connect;
            this._game = game;

            GameLogs = new ObservableCollection<BAC_GAME_OUTPUT_DATA>();
            BindingOperations.EnableCollectionSynchronization(GameLogs, _lock);

            EnterState();
        }

        #region StateModel
        protected override void EnterState()
        {
            _connect.ReceiveServerMessageOnUI += ReceiveMessageOnUI;
            
            base.EnterState();
        }
        protected override void ExitState()
        {
            base.ExitState();

            _connect.ReceiveServerMessageOnUI -= ReceiveMessageOnUI;
            bWin = false;
        }
        public override bool bValidState { get; protected set; }
        #endregion

        public event Action<BAC_GAME_RESULT_DATA>? GameEnded;

        public void SendInput(int a, int b, int c)
        {
            _connect.SendGameInput(new Infrastructure.BAC_GAME_INPUT_DATA() { A = a, B = b, C = c });
        }

        public event Action<BAC_SERVER_CONNECT_MESSAGE>? ReceivedGameOutputData;
        void ReceiveMessageOnUI(object s)
        {
            if (s is BAC_SERVER_CONNECT_MESSAGE msg)
            {
                switch (msg.type)
                {
                    case SERVER_CONNECT_MESSAGE_TYPE.REQUEST_GAME_END: OnGameEnded(msg); break;
                    case SERVER_CONNECT_MESSAGE_TYPE.SEND_GAME_OUTPUT_DATA: OnReceivedGameOutputData(msg); break;
                }
            }
        }
        void OnReceivedGameOutputData(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            GameLogs.Add(JsonConvert.DeserializeObject<BAC_GAME_OUTPUT_DATA>(msg.msg));
            ReceivedGameOutputData?.Invoke(msg);
        }
        void OnGameEnded(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            RESULT = JsonConvert.DeserializeObject<BAC_GAME_RESULT_DATA>(msg.msg);
            bWin = RESULT.WinnerClientID == _config.ClientID();
            GameEnded?.Invoke(RESULT);
        }
    }
}

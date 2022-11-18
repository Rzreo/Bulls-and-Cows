using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.MainModule
{
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.ClientServices;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using Prism.Regions;

    class ServerConnectingService : IServerConnectingService
    {
        IDDSService _dds;
        IConfigService _config;
        int cnt = 0;
        public ServerConnectingService(IDDSService dds, IConfigService config)
        {
            this._dds = dds;
            this._config = config;

            ReceiveServerMessage += OnReceiveServerMessage;
        }
        public event Action<object>? ReceiveServerMessage;
        public event Action<object>? ReceiveServerMessageOnUI;
        private void CallReceiveServerMessageEvent(object arg)
        {
            ReceiveServerMessage?.Invoke(arg);
            UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            {
                ReceiveServerMessageOnUI?.Invoke(arg);
            });
        }

        public void StartConnect()
        {
            _config.IsConnected.Value = false;
            _dds.RegisterEvent(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _config.ClientID(), CallReceiveServerMessageEvent);

            var t = new Thread(Connecting) { IsBackground = true };
            t.Start();
        }
        void Connecting()
        {
            //while (_config.IsConnected.Value == false)
            {
                _dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE),
                    new BAC_CONNECT_INIT_MESSAGE()
                    {
                        CLIENT_ID = _config.ClientID(),                       
                    });
                Thread.Sleep(200);
                cnt++;
            }
            System.Diagnostics.Debug.WriteLine(cnt);
        }
        void OnReceiveServerMessage(object s)
        {
            if (s is BAC_SERVER_CONNECT_MESSAGE msg)
            {
                switch (msg.type)
                {
                    case SERVER_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS: OnConnectSuccess(msg); break;
                }
            }
        }
        void OnConnectSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            if (_config.IsConnected.Value == true) return;

            _config.IsConnected.Value = true;
        }

        #region Client Message
        public void EnterRoom(uint id)
        {
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + _config.ClientID(),
                         new BAC_CLIENT_CONNECT_MESSAGE()
                         {
                             type = CLIENT_CONNECT_MESSAGE_TYPE.ENTER_ROOM,
                             msg = id.ToString()
                         });
        }
        public void CreateRoom(uint nMaxParticipants)
        {
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + _config.ClientID(),
                         new BAC_CLIENT_CONNECT_MESSAGE()
                         {
                             type = CLIENT_CONNECT_MESSAGE_TYPE.CREATE_ROOM,
                             msg = nMaxParticipants.ToString()
                         });
        }
        public void RequestRoomList(int nPage)
        {
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + _config.ClientID(),
                         new BAC_CLIENT_CONNECT_MESSAGE()
                         {
                             type = CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_LIST,
                             msg = nPage.ToString()
                         });
        }
        public void RequestRoomData(uint id)
        {
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + _config.ClientID(),
                        new BAC_CLIENT_CONNECT_MESSAGE()
                        {
                            type = CLIENT_CONNECT_MESSAGE_TYPE.REQUEST_ROOM_DATA,
                            msg = id.ToString()
                        });
        }
        public void SendGameInput(BAC_GAME_INPUT_DATA data)
        {
            //_dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + _config.ClientID(),
            //                    new BAC_CLIENT_CONNECT_MESSAGE()
            //                    {
            //                        type = CLIENT_CONNECT_MESSAGE_TYPE.,
            //                        msg = id.ToString()
            //                    });
        }
        #endregion
    }
}

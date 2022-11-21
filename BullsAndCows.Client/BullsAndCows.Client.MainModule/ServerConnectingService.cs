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
    using Newtonsoft.Json;
    using Prism.Regions;
    using Reactive.Bindings;
    using System.Windows;

    class ServerConnectingService : IServerConnectingService
    {
        IDDSService _dds;
        IConfigService _config;
        long connect_last_time = 0u;
        public ReactiveProperty<bool> IsConnected { get; } = new ReactiveProperty<bool>(false);
        public ServerConnectingService(IDDSService dds, IConfigService config)
        {
            this._dds = dds;
            this._config = config;

            ReceiveServerMessage += OnReceiveServerMessage;
        }

        #region SERVER MESSAGE EVENT
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
        #endregion

        #region Connecting
        public void StartConnect()
        {
            IsConnected.Value = false;
            _dds.RegisterEvent(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _config.ClientID(), CallReceiveServerMessageEvent);
   
            var t = new Thread(CheckConnectedRegular) { IsBackground = true };
            t.Start();
        }
        void CheckConnectedRegular()
        {
            Application.Current.Dispatcher.Invoke(() =>
            {
                _dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), new BAC_CONNECT_INIT_MESSAGE(){ CLIENT_ID = _config.ClientID() });
            });
            connect_last_time = DateTime.Now.ToMilli();

            while (true)
            {
                _dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE), new BAC_CONNECT_INIT_MESSAGE() { CLIENT_ID = _config.ClientID() });
                if (DateTime.Now.ToMilli() - connect_last_time > 1500)
                {
                    IsConnected.Value = false;
                }
                Thread.Sleep(1000);
            }
        }
        void OnConnectSuccess(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            connect_last_time = DateTime.Now.ToMilli();

            if (!IsConnected.Value)
            {
               IsConnected.Value = true;

            }
        }
        #endregion

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
            _dds.Write(typeof(BAC_CLIENT_CONNECT_MESSAGE), nameof(BAC_CLIENT_CONNECT_MESSAGE) + _config.ClientID(),
                                new BAC_CLIENT_CONNECT_MESSAGE()
                                {
                                    type = CLIENT_CONNECT_MESSAGE_TYPE.SEND_GAME_INPUT,
                                    msg = JsonConvert.SerializeObject(data)
                                });
        }
        #endregion
    }
}

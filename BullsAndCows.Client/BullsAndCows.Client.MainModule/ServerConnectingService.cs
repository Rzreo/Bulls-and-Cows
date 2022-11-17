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

    class ServerConnectingService : IServerConnectingService
    {
        IDDSService _dds;
        IConfigService _config;
        int cnt = 0;
        public ServerConnectingService(IDDSService dds, IConfigService config)
        {
            this._dds = dds;
            this._config = config;
        }
        public event Action<object>? ReceiveServerMessage;

        public void StartConnect()
        {
            _config.IsConnected.Value = false;
            _dds.RegisterEvent(typeof(BAC_SERVER_CONNECT_MESSAGE), nameof(BAC_SERVER_CONNECT_MESSAGE) + _config.ClientID(), ReceiveServerMessage);

            var t = new Thread(Connecting) { IsBackground = true };
            t.Start();
        }
        void Connecting()
        {
            while (true)
            {
                _dds.Write(typeof(BAC_CONNECT_INIT_MESSAGE), nameof(BAC_CONNECT_INIT_MESSAGE),
                    new BAC_CONNECT_INIT_MESSAGE()
                    {
                        CLIENT_ID = _config.ClientID()
                    });
                Thread.Sleep(_config.IsConnected.Value ? 1000 : 100);
                cnt++;
            }
        }
    }
}

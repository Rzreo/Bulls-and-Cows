using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Views.ViewModels
{
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using Prism.Commands;

    class LoginMainViewModel : ViewModelBase
    {
        IDDSService _dds;
        IConfigService _config;
        public LoginMainViewModel(IDDSService dds, IConfigService config)
        {
            this._dds = dds;
            this._config = config;

            _dds.RegisterEvent(typeof(BAC_CONNECT_MESSAGE), nameof(BAC_CONNECT_MESSAGE) + config.ClientID(), ReceiveMessage);
        }

        #region ResetNumbers
        DelegateCommand _LoginCommand;
        public DelegateCommand LoginCommand
        {
            get
            {
                if (_LoginCommand == null)
                {
                    _LoginCommand = new DelegateCommand(Login, () => { return true; });
                }
                return _LoginCommand;
            }
        }
        void Login()
        {
            _dds.Write(
                typeof(BAC_CONNECT_INIT_MESSAGE),
                nameof(BAC_CONNECT_INIT_MESSAGE),
                new BAC_CONNECT_INIT_MESSAGE() 
                { 
                    CLIENT_ID = _config.ClientID()
                });
        }
        #endregion

        void ReceiveMessage(object s)
        {
            BAC_CONNECT_MESSAGE msg = s as BAC_CONNECT_MESSAGE;
            if(msg.type == CLIENT_CONNECT_MESSAGE_TYPE.SERVER_CONNECT_SUCCESS)
            {
                System.Diagnostics.Debug.WriteLine(msg.msg);
            }
        }
    }
}

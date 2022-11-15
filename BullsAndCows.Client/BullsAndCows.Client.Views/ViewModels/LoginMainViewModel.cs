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

            _dds.RegisterEvent(typeof(Message), nameof(Message) + _config.ClientID(), LoginServerMessageReceive);
        }

        #region LoginCommand
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
            _dds.Write(typeof(BAC_CREATE_ROOM), nameof(BAC_CREATE_ROOM),
                    new BAC_CREATE_ROOM()
                    { 
                        ROOM_ID = ROOM_ID_CLIENT_REQUIRE.VALUE,
                        CLIENT_ID = _config.ClientID()
                    }
                );
        }
        #endregion

        void LoginServerMessageReceive(object s)
        {
            Message msg = s as Message;
            System.Diagnostics.Debug.WriteLine(msg.msg);
        }
    }
}

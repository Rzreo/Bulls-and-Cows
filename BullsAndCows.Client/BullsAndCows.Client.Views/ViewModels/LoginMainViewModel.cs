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
    using Prism.Commands;

    class LoginMainViewModel : ViewModelBase
    {
        IDDSService _dds;
        IConfigService _config;
        public LoginMainViewModel(IDDSService dds, IConfigService config)
        {
            this._dds = dds;
            this._config = config;
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
            _dds.Write(typeof(BAC_CREATE_ROOM), new BAC_CREATE_ROOM() { ROOM_ID = ROOM_ID_CLIENT_REQUIRE.VALUE, CLIENT_ID = $"{_config.ComputerNumber}-{_config.ProcessID}" });
        }
        #endregion
    }
}

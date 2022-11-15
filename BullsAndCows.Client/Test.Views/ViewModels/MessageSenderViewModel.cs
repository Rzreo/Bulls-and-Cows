using System;
using System.Windows;
using System.Windows.Threading;
using System.Collections.ObjectModel;
using System.Windows.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test.Views.ViewModels
{
    using Prism.Commands;
    using Prism.Ioc;
    using Test.Infrastructure;
    using RTIWrapper;
    class MessageSenderViewModel : ViewModelBase
    {
        IContainerProvider _provider;
        Net.IDDSService _dds;
        string _message = "MyMessage";
        public string CurrentMessage { get { return _message; } set { SetProperty(ref _message, value); } }
        public MessageSenderViewModel(IContainerProvider provider)
        {
            _provider = provider;
            _dds = _provider.Resolve<Net.IDDSService>();
        }

        #region SendMessage
        DelegateCommand _SendMessageCommand;
        public DelegateCommand SendMessageCommand
        {
            get
            {
                if (_SendMessageCommand == null)
                {
                    _SendMessageCommand = new DelegateCommand(SendMessage, () => { return true; });
                }
                return _SendMessageCommand;
            }
        }
        void SendMessage()
        {
            Message msg = new Message() { msg = CurrentMessage };
            _dds.Write(typeof(Message), msg);
        }
        #endregion
    }
}

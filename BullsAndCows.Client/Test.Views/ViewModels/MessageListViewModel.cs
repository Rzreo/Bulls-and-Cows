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

    using Prism.Ioc;   
    using Test.Infrastructure;
    class MessageListViewModel : ViewModelBase
    {
        object _lock = new object();
        IContainerProvider _provider;
        event Action<Message> MessageReceived;
        public ObservableCollection<string> Messages { get; set; }
        public MessageListViewModel(IContainerProvider provider)
        {
            _provider = provider;

            MessageReceived += (m) => Messages.Add(m.msg);

            // https://stackoverflow.com/questions/2091988/how-do-i-update-an-observablecollection-via-a-worker-thread
            Messages = new ObservableCollection<string>();
            BindingOperations.EnableCollectionSynchronization(Messages, _lock);
            
            var dds = _provider.Resolve<Test.Net.IDDSService>();
            dds.RegisterEvent(typeof(Message), RegisteredEvent);
        }
        void RegisteredEvent(object msg)
        {
            lock (_lock)
            {
                var m = msg as Message;
                
                MessageReceived?.Invoke(m);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Views
{
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;

    public class ViewsModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {
        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            //ViewModelLocationProvider.Register<Views.MessageList, ViewModels.MessageListViewModel>();
            //ViewModelLocationProvider.Register<Views.MessageSender, ViewModels.MessageSenderViewModel>();
            //
            //containerRegistry.RegisterForNavigation<Views.MessageList>();
            //containerRegistry.RegisterForNavigation<Views.MessageSender>();
        }
    }
}

namespace BullsAndCows.Server.Net
{
    using BullsAndCows.Infrastructure.Net;
    using Prism.Ioc;
    using Prism.Modularity;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public class NetModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {
        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            containerRegistry.RegisterSingleton<IDDSService, DDSService>();
        }
    }
}

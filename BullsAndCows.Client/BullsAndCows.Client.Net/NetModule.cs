﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Prism.Ioc;
using Prism.Modularity;

namespace BullsAndCows.Client.Net
{
    public class NetModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {
        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            // containerRegistry.RegisterSingleton<IDDSService, DDSService>();
            // 일단 귀찮으니 아래로 대체
            containerRegistry.RegisterInstance<IDDSService>(new DDSService());
        }
    }
}

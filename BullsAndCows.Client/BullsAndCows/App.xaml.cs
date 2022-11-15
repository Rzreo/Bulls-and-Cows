﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace BullsAndCows.Client
{
    using Prism.DryIoc;
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;
    using Prism.Regions;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using BullsAndCows.Client.Views;
    using BullsAndCows.Client.ViewModels;

    public partial class App : PrismApplication
    {
        protected override Window CreateShell()
        {
            return Container.Resolve<MainWindow>();
        }

        protected override void RegisterTypes(IContainerRegistry containerRegistry)
        {
            ViewModelLocationProvider.Register<MainWindow, MainWindowVM>();
        }
        protected override void ConfigureModuleCatalog(IModuleCatalog moduleCatalog)
        {
            moduleCatalog.AddModule<BullsAndCows.Client.Net.NetModule>();
            moduleCatalog.AddModule<BullsAndCows.Client.Views.ViewsModule>();
        }
        protected override void OnInitialized()
        {
            base.OnInitialized();

            var regionManager = this.Container.Resolve<IRegionManager>();
            //regionManager.RequestNavigate(MyRegion.ReceiverRegion, nameof(MessageList));
            //regionManager.RequestNavigate(MyRegion.SenderRegion, nameof(MessageSender));
        }
    }
}

using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace Publisher
{
    using Prism.DryIoc;
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;
    using Prism.Regions;
    using Publisher.ViewModels;
    using Test.Infrastructure.Utils.Regions;
    using Test.Views.Views;

    public partial class App : PrismApplication
    {
        protected override Window CreateShell()
        {
            return Container.Resolve<MainWindow>();
        }

        protected override void RegisterTypes(IContainerRegistry containerRegistry)
        {
            ViewModelLocationProvider.Register<MainWindow, MainWindowViewModel>();
        }
        protected override void ConfigureModuleCatalog(IModuleCatalog moduleCatalog)
        {
            moduleCatalog.AddModule<Test.Net.NetModule>();
            moduleCatalog.AddModule<Test.Views.ViewsModule>();
        }
        protected override void OnInitialized()
        {
            base.OnInitialized();

            var regionManager = this.Container.Resolve<IRegionManager>();
            regionManager.RequestNavigate(MyRegion.ReceiverRegion, nameof(MessageList));
            regionManager.RequestNavigate(MyRegion.SenderRegion, nameof(MessageSender));
        }
    }
}

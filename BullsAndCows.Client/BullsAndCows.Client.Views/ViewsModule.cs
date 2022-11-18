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
            ViewModelLocationProvider.Register<Views.LobbyMain, ViewModels.LoginMainViewModel>();
            ViewModelLocationProvider.Register<Views.WaitingMain, ViewModels.WaitingMainViewModel>();
            ViewModelLocationProvider.Register<Views.PlayView, ViewModels.PlayVM>();
            ViewModelLocationProvider.Register<Views.NumberInputsView, ViewModels.NumberInputsVM>();
            ViewModelLocationProvider.Register<Views.PlayLogsView, ViewModels.PlayLogsVM>();
            //ViewModelLocationProvider.Register<Views.MessageSender, ViewModels.MessageSenderViewModel>();
            
            containerRegistry.RegisterForNavigation<Views.LobbyMain>();
            containerRegistry.RegisterForNavigation<Views.WaitingMain>();
            containerRegistry.RegisterForNavigation<Views.PlayView>();
            containerRegistry.RegisterForNavigation<Views.NumberInputsView>();
            containerRegistry.RegisterForNavigation<Views.PlayLogsView>();
            //containerRegistry.RegisterForNavigation<Views.MessageSender>();
        }
    }
}

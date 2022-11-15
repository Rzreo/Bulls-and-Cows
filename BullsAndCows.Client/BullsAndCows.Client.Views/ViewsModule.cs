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
            ViewModelLocationProvider.Register<Views.PlayView, ViewModels.PlayVM>();
            ViewModelLocationProvider.Register<Views.LoginMain, ViewModels.LoginMainViewModel>();
            //ViewModelLocationProvider.Register<Views.MessageSender, ViewModels.MessageSenderViewModel>();
            
            containerRegistry.RegisterForNavigation<Views.PlayView>();
            containerRegistry.RegisterForNavigation<Views.LoginMain>();
            //containerRegistry.RegisterForNavigation<Views.MessageSender>();
        }
    }
}

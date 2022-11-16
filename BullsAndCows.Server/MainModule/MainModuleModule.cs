namespace MainModule
{
    using MainModule.ViewModels;
    using MainModule.Views;
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;
    using Prism.Regions;

    public class MainModuleModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {

        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            ViewModelLocationProvider.Register<Views.MainView, ViewModels.MainViewModel>();

            containerRegistry.RegisterForNavigation<MainView, MainViewModel>();
        }
    }
}
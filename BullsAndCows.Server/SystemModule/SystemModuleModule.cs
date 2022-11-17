namespace SystemModule
{
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;
    using Prism.Regions;
    using SystemModule.Views;

    public class SystemModuleModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {

        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            ViewModelLocationProvider.Register<Views.SystemView, ViewModels.SystemViewModel>();

            containerRegistry.RegisterForNavigation<SystemView, ViewModels.SystemViewModel>();
        }
    }
}
namespace BullsAndCows.Client.MainModule
{
    using BullsAndCows.Infrastructure.ClientServices;
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;

    public class MainModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {
        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            containerRegistry.RegisterSingleton<IServerConnectingService, ServerConnectingService>();
            containerRegistry.RegisterSingleton<IGameManageService, GameManageService>();
            containerRegistry.RegisterSingleton<LobbyStateModel>();
            containerRegistry.RegisterSingleton<WaitingStateModel>();
            containerRegistry.RegisterSingleton<PlayStateModel>();
        }
    }
}
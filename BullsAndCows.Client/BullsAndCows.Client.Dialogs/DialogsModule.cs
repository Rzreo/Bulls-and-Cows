namespace BullsAndCows.Client.Dialogs
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using Prism.Ioc;
    using Prism.Modularity;
    using Prism.Mvvm;

    public class DialogsModule : IModule
    {
        public void OnInitialized(IContainerProvider containerProvider)
        {

        }

        public void RegisterTypes(IContainerRegistry containerRegistry)
        {
            containerRegistry.RegisterDialog<Views.CreateRoomDialog, ViewModels.CreateRoomDialogVM>();
        }
    }
}

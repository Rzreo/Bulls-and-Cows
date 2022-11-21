using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Prism.Commands;
using Prism.Mvvm;
using Prism.Regions;

namespace BullsAndCows.Client.Views.ViewModels
{
    using BullsAndCows.Client.MainModule;
    using BullsAndCows.Infrastructure.BaseClass;

    class PlayLogsVM : ViewModelBase
    {
        //IRegionManager _regionManager;
        //MyModel _model;
        public PlayStateModel Model { get; private set; }
        public PlayLogsVM(IRegionManager regionManager, PlayStateModel model)
        {
            Model = model;
        }
    }
}

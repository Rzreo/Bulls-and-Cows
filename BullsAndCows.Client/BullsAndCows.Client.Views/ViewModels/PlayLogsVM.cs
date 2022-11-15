using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Prism.Commands;
using Prism.Mvvm;
using Prism.Regions;

namespace BullsandCows.Play.ViewModels
{
    using BullsandCows.Infrastructure.BaseClass;
    using BullsandCows.Models;

    class PlayLogsVM : ViewModelBase
    {
        IRegionManager _regionManager;
        MyModel _model;
        public MyModel Model => _model;
        public PlayLogsVM(IRegionManager regionManager, MyModel model)
        {
            _regionManager = regionManager;
            _model = model;
        }
    }
}

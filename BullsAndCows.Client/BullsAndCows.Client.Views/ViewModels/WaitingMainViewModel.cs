using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Prism.Regions;
using Prism.Commands;
using Prism.Mvvm;

namespace BullsAndCows.Client.Views.ViewModels
{
    using BullsAndCows.Client.MainModule;
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using Reactive.Bindings;
    using System.Windows.Data;

    class WaitingMainViewModel : ViewModelBase
    {
        IDDSService _dds;
        IConfigService _config;
        object _lock = new object();
        public WaitingStateModel Model { get; private set; }
        public WaitingMainViewModel(WaitingStateModel model, IRegionManager regionManager, IDDSService dds, IConfigService config)
        {
            _dds = dds;
            _config = config;
            Model = model;

        }
    }
}

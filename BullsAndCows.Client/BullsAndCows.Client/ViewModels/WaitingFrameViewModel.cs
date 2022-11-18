using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.ViewModels
{
    using BullsAndCows.Client.MainModule;
    using BullsAndCows.Infrastructure.BaseClass;
    internal class WaitingFrameViewModel : ViewModelBase
    {
        WaitingStateModel _model;
        public WaitingFrameViewModel(WaitingStateModel model)
        {
            _model = model;
        }
    }
}

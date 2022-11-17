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
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using Reactive.Bindings;
    using System.Windows.Data;

    class ParticipantListsViewModel : ViewModelBase
    {
        IDDSService _dds;
        IConfigService _config;
        object _lock = new object();
        public ReactiveCollection<BAC_PARTICIPANT_DATA> Participants { get; private set; }
        public ParticipantListsViewModel(IRegionManager regionManager, IDDSService dds, IConfigService config)
        {
            _dds = dds;
            _config = config;

            Participants = new ReactiveCollection<BAC_PARTICIPANT_DATA>();
            BindingOperations.EnableCollectionSynchronization(Participants, _lock);
        }
    }
}

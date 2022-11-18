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
    using BullsAndCows.Infrastructure;
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.Net;
    using Newtonsoft.Json;
    using Reactive.Bindings;

    //using BullsAndCows.Models;

    class PlayVM : ViewModelBase
    {
        public ReactiveProperty<int> Strike { get; private set; } = new ReactiveProperty<int>();
        public ReactiveProperty<int> Ball { get; private set; } = new ReactiveProperty<int>();
        public ReactiveProperty<int> Out { get; private set; } = new ReactiveProperty<int>();
        public PlayStateModel Model { get; set; }
        public List<int> Numbers { get; private set; } = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        public PlayVM(PlayStateModel model)
        {
            Model = model;

            model.ReceivedGameOutputData += OnReceivedGameOutputData;
            model.StateExited += OnStateExited;
        }
        void OnStateExited()
        {
            Model.StateExited -= OnStateExited;
            Model.ReceivedGameOutputData -= OnReceivedGameOutputData;
        }
        void OnReceivedGameOutputData(BAC_SERVER_CONNECT_MESSAGE msg)
        {
            BAC_GAME_OUTPUT_DATA data = JsonConvert.DeserializeObject<BAC_GAME_OUTPUT_DATA>(msg.msg);
            Strike.Value = data.nStrike;
            Ball.Value = data.nBall;
            Out.Value = data.nOut;
        }
    }
}

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

    class PlayVM : ViewModelBase
    {
        private GameOutput _gameOutput;
        public GameOutput GameOutput {
            get { return _gameOutput; }
            set { SetProperty(ref _gameOutput, value); }
        }
        public List<int> Numbers { get; private set; } = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        public PlayVM()
        {
        }
    }
}

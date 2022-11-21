using System;
using System.Collections.Generic;
using Prism.Commands;
using Prism.Regions;
using Prism.Services.Dialogs;

namespace BullsAndCows.Client.Views.ViewModels
{
    using BullsAndCows.Client.MainModule;
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.ClientServices;

    class SuccessVM : ViewModelBase, INavigationAware
    {
        IGameManageService _game;
        public PlayStateModel Model { get; private set; }
        public SuccessVM(PlayStateModel model, IGameManageService game)
        {
            _game = game;
            Model = model;
        }

        #region Reset
        DelegateCommand? _ResetCommand;
        public DelegateCommand ResetCommand
        {
            get
            {
                if (_ResetCommand == null)
                {
                    _ResetCommand = new DelegateCommand(Reset, () => { return true; });
                }
                return _ResetCommand;
            }
        }
        void Reset()
        {
            _game.GoToLobby();
        }
        #endregion

        #region NavigationAware
        public void OnNavigatedTo(NavigationContext navigationContext)
        {
            //_naviJournal = navigationContext.NavigationService.Journal;

        }

        public bool IsNavigationTarget(NavigationContext navigationContext)
        {
            return true;
        }

        public void OnNavigatedFrom(NavigationContext navigationContext)
        {
        }
        #endregion
    }
}

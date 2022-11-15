using System;
using System.Collections.Generic;
using Prism.Commands;
using Prism.Regions;
using Prism.Services.Dialogs;

namespace BullsAndCows.Client.Views.ViewModels
{
    using BullsAndCows.Infrastructure.BaseClass;

    class SuccessVM : ViewModelBase, INavigationAware
    {
        IDialogService _dialogService;
        IRegionNavigationJournal _naviJournal;
        /*
        MyModel _model;
        int _in_a = 0, _in_b = 0, _in_c = 0;
        public int IN_A { get { return _in_a; } set { SetProperty(ref _in_a, value % 10); } }
        public int IN_B { get { return _in_b; } set { SetProperty(ref _in_b, value % 10); } }
        public int IN_C { get { return _in_c; } set { SetProperty(ref _in_c, value % 10); } }
        public List<int> Numbers { get; private set; } = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        public SuccessVM(IDialogService dialogService, MyModel model)
        {
            _dialogService = dialogService;
            _model = model;
        }

        #region Reset
        DelegateCommand _ResetCommand;
        public DelegateCommand ResetCommand
        {
            get
            {
                if (_ResetCommand == null)
                {
                    _ResetCommand = new DelegateCommand(Reset, () => { return _naviJournal != null && _naviJournal.CanGoBack; });
                }
                return _ResetCommand;
            }
        }
        void Reset()
        {
            _dialogService.ShowDialog(nameof(ResetDialog), new DialogParameters($"message={"ㅋㅋㅋㅋ"}"), r =>
            {
                if(r.Result == ButtonResult.OK)
                {
                    _model?.ResetNumbers();
                    _naviJournal?.GoBack();
                }
            });
        }
        #endregion
        */

        #region NavigationAware
        public void OnNavigatedTo(NavigationContext navigationContext)
        {
            _naviJournal = navigationContext.NavigationService.Journal;

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

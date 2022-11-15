using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Prism.Regions;
using Prism.Commands;
using Prism.Mvvm;

namespace BullsandCows.Inputs.ViewModels
{
    using BullsandCows.Infrastructure.BaseClass;
    using BullsandCows.Infrastructure.Utils.Regions;
    using BullsandCows.Inputs.Views;
    using BullsandCows.Models;

    public interface IDoCommand
    {
        CompositeCommand Cmds { get; }
    }
    public class DoCommand : IDoCommand
    {
        private CompositeCommand _cmds = new CompositeCommand();
        public CompositeCommand Cmds
        {
            get { return _cmds; }
        }
    }

    class NumberInputsVM : ViewModelBase
    {
        IRegionManager _regionManager;
        MyModel _model;
        int _in_a = 0, _in_b = 0, _in_c = 0;
        public int IN_A { get { return _in_a; } set { SetProperty(ref _in_a, value % 10); } }
        public int IN_B { get { return _in_b; } set { SetProperty(ref _in_b, value % 10); } }
        public int IN_C { get { return _in_c; } set { SetProperty(ref _in_c, value % 10); } }
        public List<int> Numbers { get; private set; } = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        public NumberInputsVM(IRegionManager regionManager, MyModel model)
        {
            _regionManager = regionManager;
            _model = model as MyModel;
            _model.PropertyChanged += (s, e) =>
            {
                if (e.PropertyName != nameof(MyModel.State)) return;
                var t = (s as MyModel).State;
                _regionManager.RequestNavigate(
                      Region.PlayViewRegion,
                      t == MyModel.EState.Success ? "SuccessView" : "PlayView");
                PlayNumbersCommand.RaiseCanExecuteChanged();
            };

            DoCommand.Cmds.RegisterCommand(PlayNumbersCommand);
        }

        public DoCommand DoCommand { get; set; } = new DoCommand();

        #region PlayNumbers
        DelegateCommand _PlayNumbersCommand;
        public DelegateCommand PlayNumbersCommand
        {
            get
            {
                if (_PlayNumbersCommand == null)
                {
                    _PlayNumbersCommand = new DelegateCommand(() => _model?.PlayNumbers(IN_A, IN_B, IN_C), () => _model != null ? _model.CanPlayNumbers() : true);
                }
                return _PlayNumbersCommand;
            }
        }
        #endregion

        #region ResetNumbers
        DelegateCommand _ResetNumbersCommand;
        public DelegateCommand ResetNumbersCommand
        {
            get
            {
                if (_ResetNumbersCommand == null)
                {
                    _ResetNumbersCommand = new DelegateCommand(()=>_model?.ResetNumbers(), () => { return true; });
                }
                return _ResetNumbersCommand;
            }
        }
        #endregion

        #region ChangeView
        DelegateCommand _ChangeLogViewCommand;
        public DelegateCommand ChangeLogViewCommand
        {
            get
            {
                if (_ChangeLogViewCommand == null)
                {
                    _ChangeLogViewCommand = new DelegateCommand(ChangeLogView, () => { return true; });
                }
                return _ChangeLogViewCommand;
            }
        }
        void ChangeLogView()
        {
            // Hard Coding
            _regionManager.RequestNavigate(
                       Region.PlayViewRegion,
                       IsActivePlayView ? "PlayLogsView" : "PlayView");
            IsActivePlayView = !IsActivePlayView;
            RaisePropertyChanged(nameof(ViewToggleName));
        }
        public bool IsActivePlayView { get; set; } = true;
        public string ViewToggleName
        {
            get
            {
                return IsActivePlayView ? "Log" : "Play";
            }
        }
        #endregion

        #region SelectedCommand
        DelegateCommand _SelectedCommand;
        public DelegateCommand SelectedCommand
        {
            get
            {
                if (_SelectedCommand == null)
                {
                    _SelectedCommand = new DelegateCommand(() => _model.PlayNumbers(IN_A, IN_B, IN_C), () => { return true; });
                }
                return _SelectedCommand;
            }
        }
        #endregion
    }
}

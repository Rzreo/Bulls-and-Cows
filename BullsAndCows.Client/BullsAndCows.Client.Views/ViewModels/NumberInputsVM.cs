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
    using BullsAndCows.Infrastructure.ClientServices;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using Reactive.Bindings;

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
        IRegionManager _regionMgr;
        IGameManageService _game;
        PlayStateModel _model;
        int _in_a = 0, _in_b = 0, _in_c = 0;
        public int IN_A { get { return _in_a; } set { SetProperty(ref _in_a, value % 10); } }
        public int IN_B { get { return _in_b; } set { SetProperty(ref _in_b, value % 10); } }
        public int IN_C { get { return _in_c; } set { SetProperty(ref _in_c, value % 10); } }
        public List<int> Numbers { get; private set; } = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        public NumberInputsVM(PlayStateModel model, IGameManageService game, IRegionManager region)
        {
            _model = model;
            _game = game;
            _regionMgr = region;

            //_model = model as MyModel;
            //_model.PropertyChanged += (s, e) =>
            //{
            //    if (e.PropertyName != nameof(MyModel.State)) return;
            //    var t = (s as MyModel).State;
            //    _regionManager.RequestNavigate(
            //          Region.PlayViewRegion,
            //          t == MyModel.EState.Success ? "SuccessView" : "PlayView");
            //    PlayNumbersCommand.RaiseCanExecuteChanged();
            //};
            //

            DoCommand.Cmds.RegisterCommand(PlayNumbersCommand);
            model.GameEnded += OnGameEnded;
        }

        public DoCommand DoCommand { get; set; } = new DoCommand();

        #region PlayNumbers
        DelegateCommand? _PlayNumbersCommand;
        public DelegateCommand PlayNumbersCommand
        {
            get
            {
                if (_PlayNumbersCommand == null)
                {
                    _PlayNumbersCommand = new DelegateCommand(() => PlayNumbers(IN_A, IN_B, IN_C), () => true);
                }
                return _PlayNumbersCommand;
            }
        }
        void PlayNumbers(int a, int b, int c)
        {
            _model.SendInput(a, b, c);
        }
        #endregion

        #region ChangeView
        DelegateCommand? _ChangeLogViewCommand;
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
            _regionMgr.RequestNavigate(ClientRegions.Play_PlayRegion, IsActivePlayView ? "PlayLogsView" : "PlayView");
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

        void OnGameEnded(BAC_GAME_RESULT_DATA data)
        {
            _regionMgr.RequestNavigate(ClientRegions.Play_PlayRegion, nameof(SuccessView));
        }
    }
}

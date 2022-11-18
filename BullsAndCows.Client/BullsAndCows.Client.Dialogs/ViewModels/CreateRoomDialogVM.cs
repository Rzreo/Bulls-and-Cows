using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Dialogs.ViewModels
{
    using BullsAndCows.Infrastructure.BaseClass;
    using Microsoft.Xaml.Behaviors;
    using Prism.Commands;
    using Prism.Services.Dialogs;
    using System.Reflection.Metadata;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Input;

    internal class CreateRoomDialogVM : ViewModelBase, IDialogAware
    {
        #region DialogAware
        public string Title => "Create Room";

        public event Action<IDialogResult>? RequestClose;

        public bool CanCloseDialog()
        {
            return true;
        }

        public void OnDialogClosed()
        {
            
        }

        public void OnDialogOpened(IDialogParameters parameters)
        {
        }
        #endregion

        int _capacity = 1;
        public int Capacity { get { return _capacity; } set { SetProperty(ref _capacity, value); } }

        private DelegateCommand<string>? _closeDialogCommand;
        public DelegateCommand<string> CloseDialogCommand =>
            _closeDialogCommand ?? (_closeDialogCommand = new DelegateCommand<string>(CloseDialog));
        protected virtual void CloseDialog(string parameter)
        {
            ButtonResult result = ButtonResult.None;

            if (parameter?.ToLower() == "true")
                result = ButtonResult.OK;
            else if (parameter?.ToLower() == "false")
                result = ButtonResult.Cancel;
            
            var res = new DialogResult(result);
            res.Parameters.Add(nameof(Capacity), Capacity);
            RequestClose?.Invoke(res);
        }
    }

}

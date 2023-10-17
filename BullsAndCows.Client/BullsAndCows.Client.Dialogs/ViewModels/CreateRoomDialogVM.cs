using System;
using Prism.Commands;
using Prism.Services.Dialogs;
using BullsAndCows.Infrastructure.BaseClass;

namespace BullsAndCows.Client.Dialogs.ViewModels;

internal class CreateRoomDialogVM : ViewModelBase, IDialogAware
{
    public string Title => "Create Room";

    public event Action<IDialogResult>? RequestClose;

    public DelegateCommand<string> CloseDialogCommand { get; }

    public int Capacity { get { return mCapacity; } set { SetProperty(ref mCapacity, value); } }
    int mCapacity = 1;

    bool bCanClose = false;
    public CreateRoomDialogVM()
    {
        CloseDialogCommand = new DelegateCommand<string>(CloseDialog);
    }

    public bool CanCloseDialog() => bCanClose;
    public void OnDialogClosed()
    {
        
    }
    public void OnDialogOpened(IDialogParameters parameters)
    {
    }
    protected virtual void CloseDialog(string parameter)
    {
        ButtonResult result = ButtonResult.None;

        if (parameter?.ToLower() == "true")
            result = ButtonResult.OK;
        else if (parameter?.ToLower() == "false")
            result = ButtonResult.Cancel;
        
        var res = new DialogResult(result);
        res.Parameters.Add(nameof(Capacity), Capacity);

        bCanClose = true;
        RequestClose?.Invoke(res);
    }
}

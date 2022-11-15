namespace BullsAndCows.Infrastructure.OperationManagement
{
    using Reactive.Bindings;
    public interface IConfigService
    {
        ReactiveProperty<int> ComputerNumber { get; }
        ReactiveProperty<int> ProcessID { get; }
    }
}

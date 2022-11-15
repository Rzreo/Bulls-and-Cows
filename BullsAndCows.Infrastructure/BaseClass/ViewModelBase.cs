namespace BullsAndCows.Infrastructure
{
    using System;
    using Prism.Mvvm;
    using Prism.Navigation;
    using System.Reactive.Disposables;

    public class ViewModelBase : BindableBase, IDisposable, IDestructible
    {
        private bool disposedValue;

        protected CompositeDisposable Disposables { get; } = new CompositeDisposable();

        public void Destroy() => this.Dispose();
        public void Dispose()
        {
            this.Dispose(true);
            GC.SuppressFinalize(this);
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!this.disposedValue)
            {
                if (disposing)
                {
                    this.Disposables.Dispose();
                }

                this.disposedValue = true;
            }
        }
    }
}

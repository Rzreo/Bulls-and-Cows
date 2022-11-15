using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Infrastructure.BaseClass
{
    using System;
    using System.Reactive.Disposables;

    /// <summary>
    /// Service 구현 시 Dispose를 명시적으로 호출하여 해제해주는 형태를 구현한 클래스.
    /// </summary>
    /// <seealso cref="IDisposable"/>
    public class DisposableService : IDisposable
    {
        private bool disposedValue;

        protected CompositeDisposable Disposables { get; } = new CompositeDisposable();

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

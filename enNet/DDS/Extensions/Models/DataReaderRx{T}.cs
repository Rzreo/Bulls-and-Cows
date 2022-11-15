using System;
using System.Reactive.Linq;

namespace enNet
{
    /// <summary>
    /// Generic 형태의 DataReaderRx
    /// </summary>
    /// <typeparam name="T">DataReaderRx 의 Topic Data Type</typeparam>
    public sealed class DataReaderRx<T> : IDisposable
    {
        private readonly DataReaderRx dataReaderRx;

        public DataReaderRx(DataReaderRx dataReaderRx)
        {
            this.dataReaderRx = dataReaderRx ?? throw new ArgumentNullException(nameof(dataReaderRx));
            if (!(this.dataReaderRx.GetDataType() == typeof(T))) throw new InvalidOperationException(nameof(T));
        }

        public void Dispose()
        {
            this.dataReaderRx.Dispose();
        }

        public IObservable<T> Samples => this.dataReaderRx.Samples.Cast<T>();
    }
}
using System;

namespace enNet
{
    public interface IDataReader<T>
    {
        IObservable<T> Samples { get; }
    }
}
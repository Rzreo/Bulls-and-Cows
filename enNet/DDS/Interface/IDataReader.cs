using System;

namespace enNet
{
    public interface IDataReader
    {
        IObservable<object> Samples { get; }
    }
}
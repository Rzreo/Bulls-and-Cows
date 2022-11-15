using System;

namespace enNet
{
    public interface IDataReaderRx
    {
        DDS.Topic Topic { get; }
        IObservable<object> Samples { get; }
    }
}
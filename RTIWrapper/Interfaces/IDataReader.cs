using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RTIWrapper
{
    public interface IDataReaderRx
    {
        IObservable<object> Samples { get; }
        DDS.Topic Topic { get; }
        void Dispose();
    }
}

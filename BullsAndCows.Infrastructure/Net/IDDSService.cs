using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Infrastructure.Net
{
    public interface IDDSService
    {
        /// <summary>
        /// Gets the value of the debug model.
        /// </summary>
        //DebugModel DebugModel { get; }

        bool DeleteDataReader(Type type, string topic);

        void RegisterEvent(Type type, string topic, Action<object> readerAction);

        void RegisterEvent(Type type, string topic, Action callbackFunc);

        bool Write(Type type, string topic, object message);
    }
}

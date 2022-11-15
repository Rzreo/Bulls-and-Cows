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

        bool DeleteDataReader(Type type);

        void RegisterEvent(Type type, Action<object> readerAction);

        void RegisterEvent(Type type, Action callbackFunc);

        bool Write(Type type, object message);
    }
}

using Reactive.Bindings;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Infrastructure.ClientServices
{
    public interface IServerConnectingService
    {
        void StartConnect();
        event Action<object> ReceiveServerMessage;
    }
}

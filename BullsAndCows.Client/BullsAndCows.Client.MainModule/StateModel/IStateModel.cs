using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.MainModule.StateModel
{
    public interface IStateModel
    {
        void EnterState();
        void ExitState();
        bool bValidState { get; }
    }
}

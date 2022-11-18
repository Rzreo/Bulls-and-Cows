using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.MainModule
{
    public abstract class StateModel
    {
        protected abstract void EnterState();
        protected abstract void ExitState();
        public abstract bool bValidState { get; protected set; }
    }
}

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.MainModule
{
    public abstract class StateModel
    {
        public event Action? StateEntered;
        public event Action? StateExited;
        protected virtual void EnterState() { StateEntered?.Invoke(); bValidState = true; }
        protected virtual void ExitState() { bValidState = false; StateExited?.Invoke(); }
        public abstract bool bValidState { get; protected set; }
    }
}

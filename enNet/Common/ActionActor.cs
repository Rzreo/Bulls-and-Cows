using Akka.Actor;
using System;

namespace enNet
{
    internal class ActionActor : ReceiveActor
    {
        public ActionActor()
        {
            Receive<Action>(action => action());
        }

        protected override void Unhandled(object message)
        {
            //Unhandled message
        }
    }
}
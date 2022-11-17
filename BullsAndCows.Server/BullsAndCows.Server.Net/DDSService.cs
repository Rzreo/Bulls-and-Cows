using BullsAndCows.Infrastructure.Net;
using Reactive.Bindings;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Server.Net
{
    public class MSGcontainer
    {
        public DateTime dateTime { get; set; }
        public string sender { get; set; }
        public object data { get; set; }

        public MSGcontainer(DateTime dateTime, string sender, object data)
        {
            this.dateTime = dateTime;
            this.sender = sender;
            this.data = data;
        }
    }

    public class DDSService : IDDSService
    {
        public ReactiveCollection<MSGcontainer> RCVmessages { get; set; } = new ReactiveCollection<MSGcontainer>();
        public ReactiveCollection<MSGcontainer> SNDmessages { get; set; } = new ReactiveCollection<MSGcontainer>();
        private DDSManager DDSManagement;

        private Dictionary<Type, List<IDisposable>> SubscribedDDSObservable { get; } = new Dictionary<Type, List<IDisposable>>();


        //private int LOG_CAPACITY = 100;
        private int LOG_CAPACITY = 20;

        //string LOAD_FILE = ".\\Domain.ini";

        int domainId = 1;

        public DDSService()
        {
            //Todo ConfigFile Load

            domainId = 1;

            this.DDSManagement = new DDSManager(domainId, "chocolate_factory_Library", "N/A", 123);

            foreach (var t in this.DDSManagement.DataReaderQOSDic.Keys)
            {
                this.SubscribedDDSObservable[t] = new List<IDisposable>();
            }
        }


        public bool Write(Type type, string topic, object message)
        {
            var writer = this.DDSManagement.GetDataWriter(type, topic);
            if (writer is null)
            {
                return false;
            }
            writer.Write(message);
            SNDmessages.Add(new MSGcontainer(DateTime.Now, topic, message));
            return true;
        }
        
        public bool DeleteDataReader(Type type, string topic)
        {
            this.SubscribedDDSObservable[type].ForEach(disposable => disposable.Dispose());

            this.SubscribedDDSObservable[type].Clear();

            return this.DDSManagement.DeleteDataReader(type, topic);
        }
        public void RegisterEvent(Type type, string topic, Action<object> readerAction)
        {
            var disposable = this.DDSManagement.GetDataReader(type, topic).Samples.ObserveOn(UIDispatcherScheduler.Default).Subscribe(data =>
            {
                RCVmessages.Add(new MSGcontainer(DateTime.Now, topic, data));
                readerAction.Invoke(data);
            });
            this.SubscribedDDSObservable[type].Add(disposable);
        }

        public void RegisterEvent(Type type, string topic, Action callbackFunc)
        {
            var disposable = this.DDSManagement.GetDataReader(type, topic).Samples.ObserveOn(UIDispatcherScheduler.Default).Subscribe(_ =>
            {
                RCVmessages.Add(new MSGcontainer(DateTime.Now, topic, _));
                callbackFunc.Invoke();
            });
            this.SubscribedDDSObservable[type].Add(disposable);
        }

        public void SendClearEvent()
        {
            SNDmessages.Clear();
        }

        public void RecvClearEvent()
        {
            RCVmessages.Clear();
        }
    }
}

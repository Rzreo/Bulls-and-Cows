﻿namespace BullsAndCows.Client.Net
{
    using System;
    using System.Collections.Generic;
    using BullsAndCows.Infrastructure.Net;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    using RTIWrapper;

    class DDSService : IDDSService
    {
        private readonly DDSManager ddsManagement;
        private Dictionary<Type, List<IDisposable>> SubscribedDDSObservable { get; } = new Dictionary<Type, List<IDisposable>>();
        public DDSService() //  DDSService(IConfigService config)
        {
            this.ddsManagement = new DDSManager(1, "BullsAndCows_Library", "N/A", 123);

            foreach (var t in this.ddsManagement.DataReaderQOSDic.Keys)
            {
                this.SubscribedDDSObservable[t] = new List<IDisposable>();
            }
        }

        public bool DeleteDataReader(Type type)
        {
            this.SubscribedDDSObservable[type].ForEach(disposable => disposable.Dispose());

            this.SubscribedDDSObservable[type].Clear();

            return this.ddsManagement.DeleteDataReader(type);
        }

        public void RegisterEvent(Type type, Action<object> readerAction)
        {
            var disposable = this.ddsManagement.GetDataReader(type).Samples.Subscribe(data =>
            {
                //if (this.DebugModel.IsPopupOpened)
                //{
                //    UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
                //    {
                //        this.DebugModel.UpdateReceiveTopicList(data);
                //    });
                //}
                //
                readerAction.Invoke(data);
            });

            this.SubscribedDDSObservable[type].Add(disposable);
        }

        public void RegisterEvent(Type type, Action callbackFunc)
        {
            var disposable = this.ddsManagement.GetDataReader(type).Samples.Subscribe(_ =>
            {

                //if (this.DebugModel.IsPopupOpened)
                //{
                //    UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
                //    {
                //        this.DebugModel.UpdateReceiveTopicList(data);
                //    });
                //}
                //
                callbackFunc.Invoke();
            });

            this.SubscribedDDSObservable[type].Add(disposable);
        }

        public bool Write(Type type, object message)
        {
            var writer = this.ddsManagement.GetDataWriter(type);
            if (writer is null)
            {
                return false;
            }

            writer.Write(message);

            //UIThreadHelper.CheckAndInvokeOnUIDispatcher(() =>
            //{
            //    this.DebugModel.UpdateSendTopicList(message);
            //});

            return true;
        }
    }
}

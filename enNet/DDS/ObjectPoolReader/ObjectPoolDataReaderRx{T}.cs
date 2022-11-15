using Akka.Actor;
using System;
using System.Reactive.Linq;
using System.Reactive.Subjects;

namespace enNet
{
    public sealed class ObjectPoolDataReaderRx : IDataReaderRx, IDisposable
    {
        private DDS.Subscriber subscriber;
        private DDS.DomainParticipant participant;

        private Subject<object> sampleSubject = new Subject<object>();

        private DDS.DataReader dataReader;

        public ObjectPoolDataReaderRx(DDS.Subscriber subscriber, DDS.Topic topic, string libraryName, string profileName, int queueSize)
        {
            this.subscriber = subscriber;
            this.Topic = topic;

            var type = topic.GetDataType();
            var constructed = typeof(ObjectPoolDataReaderListener<>).MakeGenericType(new Type[] { type });
            var listener = (DDS.DataReaderListener)Activator.CreateInstance(constructed, new object[] { this.sampleSubject, queueSize });

            this.dataReader = subscriber.CreateDataReaderWithProfile(topic, libraryName, profileName, listener);
            if (this.dataReader == default) this.dataReader = subscriber.CreateDataReader(topic, listener);
            if (this.dataReader == default) throw new InvalidOperationException();
        }

        public ObjectPoolDataReaderRx(DDS.DomainParticipant participant, DDS.Topic topic, string libraryName, string profileName, int queueSize)
        {
            this.participant = participant;
            this.Topic = topic;

            var type = topic.GetDataType();
            var constructed = typeof(ObjectPoolDataReaderListener<>).MakeGenericType(new Type[] { type });
            var listener = (DDS.DataReaderListener)Activator.CreateInstance(constructed, new object[] { this.sampleSubject, queueSize });

            this.dataReader = participant.CreateDataReaderWithProfile(topic, libraryName, profileName, listener);
            if (this.dataReader == null) this.dataReader = participant.CreateDataReader(topic, listener);
            if (this.dataReader == null) throw new InvalidOperationException();
        }

        public void Dispose()
        {
            this.subscriber?.delete_datareader(ref this.dataReader);
            this.participant?.delete_datareader(ref this.dataReader);
            this.sampleSubject.Dispose();
        }

        public DDS.Topic Topic { get; }
        public IObservable<object> Samples => this.sampleSubject.AsObservable();
    }

    public class ObjectPoolDataReaderListener<T> : DDS.DataReaderListener where T : class, DDS.ICopyable<T>, new()
    {
        private Subject<object> sampleSubject;
        private ObjectPool<T> objectPool;

        public ObjectPoolDataReaderListener(Subject<object> sampleSubject, IActorRef sampleActor, int queueSize)
        {
            this.sampleSubject = sampleSubject;
            this.objectPool = new ObjectPool<T>(queueSize);
        }

        public override void on_data_available(DDS.DataReader reader)
        {
            var dataReader = (DDS.TypedDataReader<T>)reader;

            var userRefSequence = new DDS.UserRefSequence<T>();
            var sampleInfoSeq = new DDS.SampleInfoSeq();

            try
            {
                dataReader.take(
                    userRefSequence,
                    sampleInfoSeq,
                    DDS.ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    DDS.SampleStateKind.ANY_SAMPLE_STATE,
                    DDS.ViewStateKind.ANY_VIEW_STATE,
                    DDS.InstanceStateKind.ANY_INSTANCE_STATE);

                for (int idx = 0; idx < userRefSequence.length; ++idx)
                {
                    if (sampleInfoSeq.get_at(idx).valid_data)
                    {
                        var sample = objectPool.Get();
                        sample.copy_from(userRefSequence.get_at(idx));
                        sampleSubject.OnNext(sample);
                    }
                }
            }
            catch (DDS.Retcode_NoData)
            {
                //logger.Error($"{typeof(T).Name}|{nameof(on_data_available)}|{nameof(DDS.Retcode_NoData)}");
            }
            catch (Exception)
            {
                //logger.Error($"{typeof(T).Name}|{nameof(on_data_available)}|{nameof(Exception)}");
            }
            finally
            {
                dataReader.return_loan(userRefSequence, sampleInfoSeq);
            }
        }

        public override void on_liveliness_changed(DDS.DataReader reader, ref DDS.LivelinessChangedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_liveliness_changed)}");
        }

        public override void on_requested_deadline_missed(DDS.DataReader reader, ref DDS.RequestedDeadlineMissedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_requested_deadline_missed)}");
        }

        public override void on_requested_incompatible_qos(DDS.DataReader reader, DDS.RequestedIncompatibleQosStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_requested_incompatible_qos)}");
        }

        public override void on_sample_lost(DDS.DataReader reader, ref DDS.SampleLostStatus status)
        {
            //var last_reason = status.last_reason.ToString();
            //logger.Error($"{typeof(T).Name}|{nameof(on_sample_lost)}|{last_reason}");
        }

        public override void on_sample_rejected(DDS.DataReader reader, ref DDS.SampleRejectedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_sample_rejected)}");
        }

        public override void on_subscription_matched(DDS.DataReader reader, ref DDS.SubscriptionMatchedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_subscription_matched)}");
        }
    }
}
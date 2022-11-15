using System;
using System.Reactive.Linq;
using System.Reactive.Subjects;

namespace enNet
{
    /// <summary>
    /// 수신된 데이터를 Object 로 관리하며 Rx 형태로 전달
    /// </summary>
    public sealed class DataReaderRx : IDataReaderRx
    {
        private readonly DDS.Subscriber subscriber;
        private readonly DDS.DomainParticipant participant;

        private readonly Subject<object> sampleSubject = new Subject<object>();

        private DDS.DataReader dataReader;

        public DataReaderRx(DDS.Subscriber subscriber, DDS.Topic topic, string libraryName = default, string profileName = default)
        {
            this.subscriber = subscriber;
            this.Topic = topic;

            var type = topic.GetDataType();
            var constructed = typeof(Listener<>).MakeGenericType(new Type[] { type });
            var listener = (DDS.DataReaderListener)Activator.CreateInstance(constructed, new object[] { this.sampleSubject });

            this.dataReader = subscriber.CreateDataReaderWithProfile(topic, libraryName, profileName, listener);
            if (this.dataReader == default) this.dataReader = subscriber.CreateDataReader(topic, listener);
            if (this.dataReader == default) throw new InvalidOperationException();
        }

        public DataReaderRx(DDS.DomainParticipant participant, DDS.Topic topic, string libraryName = default, string profileName = default)
        {
            this.participant = participant;
            this.Topic = topic;

            var type = topic.GetDataType();
            var constructed = typeof(Listener<>).MakeGenericType(new Type[] { type });
            var listener = (DDS.DataReaderListener)Activator.CreateInstance(constructed, new object[] { this.sampleSubject });

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

    /// <summary>
    /// DataReaderListener
    /// </summary>
    /// <typeparam name="T">수신 타입</typeparam>
    internal class Listener<T> : DDS.DataReaderListener where T : class, DDS.ICopyable<T>, new()
    {
        private readonly Subject<object> sampleSubject;

        public Listener(Subject<object> sampleSubject)
        {
            this.sampleSubject = sampleSubject;
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

                for (int idx = 0; idx < userRefSequence.length; idx++)
                {
                    if (sampleInfoSeq.get_at(idx).valid_data)
                    {
                        var sample = new T();
                        sample.copy_from(userRefSequence.get_at(idx));
                        this.sampleSubject.OnNext(sample);
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
            //logger.Error($"{typeof(T).Name}|{nameof(on_liveliness_changed)}|{DateTime.Now.ToString("yy.MM.dd - hh_mm_ss.fff")}");
        }

        public override void on_requested_deadline_missed(DDS.DataReader reader, ref DDS.RequestedDeadlineMissedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_requested_deadline_missed)}|{DateTime.Now.ToString("yy.MM.dd - hh_mm_ss.fff")}");
        }

        public override void on_requested_incompatible_qos(DDS.DataReader reader, DDS.RequestedIncompatibleQosStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_requested_incompatible_qos)}|{DateTime.Now.ToString("yy.MM.dd - hh_mm_ss.fff")}");
        }

        public override void on_sample_lost(DDS.DataReader reader, ref DDS.SampleLostStatus status)
        {
            //var last_reason = status.last_reason.ToString();
            //logger.Error($"{typeof(T).Name}|{nameof(on_sample_lost)}|{last_reason}|{DateTime.Now.ToString("yy.MM.dd - hh_mm_ss.fff")}");
        }

        public override void on_sample_rejected(DDS.DataReader reader, ref DDS.SampleRejectedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_sample_rejected)}|{DateTime.Now.ToString("yy.MM.dd - hh_mm_ss.fff")}");
        }

        public override void on_subscription_matched(DDS.DataReader reader, ref DDS.SubscriptionMatchedStatus status)
        {
            //logger.Error($"{typeof(T).Name}|{nameof(on_subscription_matched)}|{DateTime.Now.ToString("yy.MM.dd - hh_mm_ss.fff")}");
        }
    }
}
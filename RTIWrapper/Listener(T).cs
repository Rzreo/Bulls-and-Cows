using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RTIWrapper
{
    using System;
    using System.Reactive.Subjects;

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
                dataReader.take(userRefSequence, sampleInfoSeq,
                    DDS.ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    DDS.SampleStateKind.ANY_SAMPLE_STATE,
                    DDS.ViewStateKind.ANY_VIEW_STATE,
                    DDS.InstanceStateKind.ANY_INSTANCE_STATE);

                for (int idx = 0; idx < userRefSequence.length; idx++)
                {
                    //sampleInfoSeq.get_at(idx).sample_state
                    //sampleInfoSeq.get_at(idx).instance_state
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
                // logger.Error($"{typeof(T).Name}|{nameof(on_data_available)}|{nameof(DDS.Retcode_NoData)}");
            }
            catch (Exception e)
            {
                // logger.Error($"{typeof(T).Name}|{nameof(on_data_available)}|{nameof(Exception)}");
            }
            finally
            {
                dataReader.return_loan(userRefSequence, sampleInfoSeq);
            }
        }
    }
}

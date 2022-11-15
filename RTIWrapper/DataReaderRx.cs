namespace RTIWrapper
{
    using System;
    using System.Reactive.Linq;
    using System.Reactive.Subjects;

    public sealed class DataReaderRx : IDataReaderRx
    {
        private readonly DDS.DomainParticipant participant;

        private readonly Subject<object> sampleSubject = new Subject<object>();

        private readonly DDS.Subscriber subscriber;

        private DDS.DataReader dataReader;
        public DataReaderRx(DDS.DomainParticipant participant, DDS.Topic topic, string libraryName = default, string profileName = default)
        {
            this.participant = participant;
            this.Topic = topic;

            var type = topic.GetDataType();
            var constructed = typeof(Listener<>).MakeGenericType(new Type[] { type });
            var listener = (DDS.DataReaderListener)Activator.CreateInstance(constructed, new object[] { this.sampleSubject });

            this.dataReader = participant.CreateDataReaderWithProfile(topic, libraryName, profileName, listener);
            if (this.dataReader == null)
            {
                this.dataReader = participant.CreateDataReader(topic, listener);
            }

            if (this.dataReader == null)
            {
                throw new InvalidOperationException();
            }
           
        }

        /// <summary>
        /// Gets the value of the samples.
        /// </summary>
        public IObservable<object> Samples => this.sampleSubject.AsObservable();

        /// <summary>
        /// Gets the value of the topic.
        /// </summary>
        public DDS.Topic Topic { get; }

        /// <summary>
        /// Disposes this instance.
        /// </summary>
        public void Dispose()
        {
            this.dataReader?.delete_contained_entities();
            this.subscriber?.delete_datareader(ref this.dataReader);
            this.participant?.delete_datareader(ref this.dataReader);
            this.sampleSubject.Dispose();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Net
{
    using DDS;
    using RTIWrapper;
    using System.Collections.Concurrent;

    /// </summary>
    public partial class DDSManager
    {
        private readonly DomainParticipant defaultParticipant;
        private readonly Publisher defaultPublisher;
        private readonly Subscriber defaultSubscriber;
        private readonly PostProcessing postProcessing;

        private readonly bool isLibraryApplied = false;
        private readonly string libraryName;

        public DDSManager(int domainID, int occNumber)
        {
            this.DataReaderQOSDic = BuildDataReaderQOS();
            this.DataWriterQoSDic = BuildDataWriterQOS();

            this.postProcessing = new PostProcessing(domainID, new Dictionary<Type, (byte Label, byte Slabel)>(), (byte)occNumber); //= new PostProcessing(domainID, BuildLabel(this.DataWriterQoSDic), (byte)occNumber);
            this.defaultParticipant = DomainParticipantFactory.get_instance().CreateParticipant(domainID); // occ Number
            this.defaultSubscriber = this.defaultParticipant.CreateSubscriber();
            this.defaultPublisher = this.defaultParticipant.CreatePublisher();

            IsEnabled = true;
        }
        public DDSManager(int domainID, string libraryName, string profileName, int occNumber)
        {
            this.libraryName = libraryName;
            this.isLibraryApplied = true;

            this.DataReaderQOSDic = BuildDataReaderQOS();
            this.DataWriterQoSDic = BuildDataWriterQOS();

            this.defaultParticipant = DomainParticipantFactory.get_instance().CreateParticipant(domainID); // occ Number
            this.defaultSubscriber = this.defaultParticipant.CreateSubscriber();
            this.defaultPublisher = this.defaultParticipant.CreatePublisher();

            IsEnabled = true;
        }

        public bool IsEnabled { get; set; }

        #region DataWriter
        private readonly ConcurrentDictionary<(Type,string), IDataWriter> dataWriterDictionary = new ConcurrentDictionary<(Type,string), IDataWriter>();
        public IDataWriter GetDataWriter(Type type, string topic)
        {
            if (type == null || topic == null)
            {
                return null;
            }
            var tp = ValueTuple.Create(type, topic);

            if (!this.dataWriterDictionary.ContainsKey(tp))
            {
                var dataWriter = this.CreateDataWriter(type, topic);
                this.dataWriterDictionary[tp] = dataWriter;
            }

            return this.dataWriterDictionary[tp];
        }
        private IDataWriter CreateDataWriter(Type type, string topicName)
        {
            var topic = this.defaultParticipant.CreateTopic(type, topicName);

            DDS.DataWriter dataWriter;

            if (this.isLibraryApplied)
            {
                if (this.DataWriterQoSDic.ContainsKey(type))
                {
                    dataWriter = this.defaultPublisher.CreateDataWriterWithProfile(topic, this.libraryName, this.DataWriterQoSDic[type]);
                }
                else
                {
                    dataWriter = this.defaultPublisher.CreateDataWriter(topic);
                }
            }
            else
            {
                dataWriter = this.defaultPublisher.CreateDataWriter(topic);
            }
            
            if (dataWriter == null)
            {
                throw new InvalidOperationException();
            }
            
            return new DataWriter(this, dataWriter, this.postProcessing);
        }
        #endregion

        #region DataReader
        private readonly ConcurrentDictionary<(Type, string), IDataReader> dataReaderDictionary = new ConcurrentDictionary<(Type, string), IDataReader>();

        public bool DeleteDataReader(Type type, string topic)
        {
            var tp = ValueTuple.Create(type, topic);

            if (this.dataReaderDictionary.TryRemove(tp, out IDataReader reader))
            {
                reader.Dispose();
                return true;
            }
            else
            {
                return false;
            }
        }
        public IDataReader GetDataReader(Type type, string topic)
        {
            if (type == null || topic == null)
            {
                return null;
            }
            var tp = ValueTuple.Create(type, topic);

            if (!this.dataReaderDictionary.ContainsKey(tp))
            {
                var dataReader = this.CreateDataReader(type, topic);
                this.dataReaderDictionary[tp] = dataReader;
            }

            return this.dataReaderDictionary[tp];
        }
        private IDataReader CreateDataReader(Type type, string topicName)
        {
            var topic = this.defaultParticipant.CreateTopic(type, topicName);

            if (this.isLibraryApplied)
            {
                if (this.DataReaderQOSDic.ContainsKey(type))
                {
                    var dataReader = new DataReaderRx(this.defaultParticipant, topic, this.libraryName, this.DataReaderQOSDic[type]);
                    return new DataReader(this, dataReader);
                }
                else
                {
                    var dataReader = new DataReaderRx(this.defaultParticipant, topic);
                    return new DataReader(this, dataReader);
                }
            }
            else
            {
                var dataReader = new DataReaderRx(this.defaultParticipant, topic);

                return new DataReader(this, dataReader);
            }
        }
        #endregion
    }
}

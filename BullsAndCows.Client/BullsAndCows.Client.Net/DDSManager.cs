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
        private readonly string libraryName = "chocolate_factory_Library";

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
            InitializeDataWriter();
        }

        public bool IsEnabled { get; set; }
        public void InitializeDataWriter()
        {
            foreach (var t in this.DataWriterQoSDic)
            {
                this.GetDataWriter(t.Key);
            }
        }

        #region DataWriter
        private readonly ConcurrentDictionary<Type, IDataWriter> dataWriterDictionary = new ConcurrentDictionary<Type, IDataWriter>();
        public IDataWriter GetDataWriter(Type type)
        {
            if (type == null)
            {
                return null;
            }

            if (!this.dataWriterDictionary.ContainsKey(type))
            {
                var dataWriter = this.CreateDataWriter(type);
                this.dataWriterDictionary[type] = dataWriter;
            }

            return this.dataWriterDictionary[type];
        }
        private IDataWriter CreateDataWriter(Type type)
        {
            var topic = this.defaultParticipant.CreateTopic(type);

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
        private readonly ConcurrentDictionary<Type, IDataReader> dataReaderDictionary = new ConcurrentDictionary<Type, IDataReader>();

        public bool DeleteDataReader(Type type)
        {
            if (this.dataReaderDictionary.TryRemove(type, out IDataReader reader))
            {
                reader.Dispose();
                return true;
            }
            else
            {
                return false;
            }
        }
        public IDataReader GetDataReader(Type type)
        {
            if (type == null)
            {
                return null;
            }

            if (!this.dataReaderDictionary.ContainsKey(type))
            {
                var dataReader = this.CreateDataReader(type);
                this.dataReaderDictionary[type] = dataReader;
            }

            return this.dataReaderDictionary[type];
        }
        private IDataReader CreateDataReader(Type type)
        {
            var topic = this.defaultParticipant.CreateTopic(type);

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

namespace BullsAndCows.Server.Net
{
    using DDS;
    using RTIWrapper;
    using System;
    using System.Collections.Concurrent;
    using System.Collections.Generic;
    using System.Data;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public partial class DDSManager
    {
        /// <summary>
        /// DDS Domain ID
        /// </summary>
        private int domain;

        /// <summary>
        /// 초기화 여부
        /// </summary>
        private bool isInitialized;

        private string LibraryName;

        /// <summary>
        /// 생성된 기본 Participant
        /// </summary>
        private DomainParticipant defaultParticipant;

        /// <summary>
        /// 생성된 기본 Subscriber
        /// </summary>
        private Subscriber defaultSubscriber;

        /// <summary>
        /// 생성된 기본 Publisher
        /// </summary>
        private Publisher defaultPublisher;

        private PostProcessing postProcessing;

        /// <summary>
        /// Manager 사용 가능 여부
        /// </summary>
        public bool IsEnabled { get; set; }

        private bool isLibraryApplied;

        private InstanceHandle_t handle;

        /// <summary>
        /// Default QOS로 Participant 생성
        /// </summary>
        /// <param name="domainID">Pariticpant가 사용할 Domain ID</param>
        public DDSManager(int domainID, int occNumber)
        {
            NDDS.ConfigLogger.get_instance().set_verbosity(NDDS.LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_SILENT);

            this.DataReaderQOSDic = BuildDataReaderQOS();

            this.DataWriterQoSDic = BuildDataWriterQOS();

            this.domain = domainID;

            this.defaultParticipant = DomainParticipantFactory.get_instance().CreateParticipant(domainID);

            this.defaultSubscriber = this.defaultParticipant.CreateSubscriber();
            this.defaultPublisher = this.defaultParticipant.CreatePublisher();

            this.postProcessing = new PostProcessing(domainID, new Dictionary<Type, (byte Label, byte Slabel)>(), (byte)occNumber); //= new PostProcessing(domainID, BuildLabel(this.DataWriterQoSDic), (byte)occNumber);


            //this.handle = this.defaultParticipant.get_instance_handle();
            //this.defaultParticipant.ignore_participant(ref this.handle); //자기 자신은 무시

            this.isInitialized = true;
            this.IsEnabled = true;

            InitializeDataWriter();
        }

        /// <summary>
        /// QOS를 적용하여 Participant 생성
        /// </summary>
        /// <param name="domainID">Pariticpant가 사용할 Domain ID</param>
        /// <param name="libraryName">USER_QOS_PROFILES내의 OQS Library Name</param>
        /// <param name="profileName">Library 하부의 QOS_Profile의 Name</param>
        public DDSManager(int domainID, string libraryName, string profileName, int occNumber)
        {
            LibraryName = libraryName;

            NDDS.ConfigLogger.get_instance().set_verbosity(NDDS.LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_SILENT);

            this.DataReaderQOSDic = BuildDataReaderQOS();

            this.DataWriterQoSDic = BuildDataWriterQOS();

            this.domain = domainID;

            this.postProcessing = new PostProcessing(domainID, new Dictionary<Type, (byte Label, byte Slabel)>(), (byte)occNumber); //= new PostProcessing(domainID, BuildLabel(this.DataWriterQoSDic), (byte)occNumber);

            this.defaultParticipant = DomainParticipantFactory.get_instance().CreateParticipant(domainID);

            this.defaultSubscriber = this.defaultParticipant.CreateSubscriber();
            this.defaultPublisher = this.defaultParticipant.CreatePublisher();

            //this.handle = this.defaultParticipant.get_instance_handle();
            //this.defaultParticipant.ignore_participant(ref this.handle); //자기 자신은 무시


            this.isInitialized = true;
            this.IsEnabled = true;
            this.isLibraryApplied = true;
            InitializeDataWriter();
        }

        public void InitializeDataWriter()
        {

        }








        #region dataWriter
        private ConcurrentDictionary<(Type,string), IDataWriter> dataWriterDictionary = new ConcurrentDictionary<(Type,string), IDataWriter>();

        /// <summary>
        /// DataWriter 생성
        /// </summary>
        /// <param name="type">사용되는 DDS Type</param>
        /// <returns></returns>
        public IDataWriter GetDataWriter(Type type, string topic)
        {
            if (type == null) return null;

            var tp = ValueTuple.Create(type, topic);

            if (!this.dataWriterDictionary.ContainsKey(tp))
            {
                var dataWriter = CreateDataWriter(type, topic);
                this.dataWriterDictionary[tp] = dataWriter;
            }

            return this.dataWriterDictionary[tp];
        }

        private IDataWriter CreateDataWriter(Type type, string topicName)
        {
            var topic = this.defaultParticipant.CreateTopic(type, topicName);

            DDS.DataWriter dataWriter;

            if (isLibraryApplied)
            {
                if (DataWriterQoSDic.ContainsKey(type))
                {
                    dataWriter = this.defaultPublisher.CreateDataWriterWithProfile(topic, LibraryName, DataWriterQoSDic[type]);
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

            if (dataWriter == null) throw new InvalidOperationException();

            return new DataWriter(this, dataWriter);
        }
        #endregion

        #region dataReader

        private ConcurrentDictionary<(Type,string), IDataReader> dataReaderDictionary = new ConcurrentDictionary<(Type,string), IDataReader>();

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
            if (type == null || topic == null) return null;

            var tp = ValueTuple.Create(type, topic);

            if (!this.dataReaderDictionary.ContainsKey(tp))
            {
                var dataReader = CreateDataReader(type, topic);
                this.dataReaderDictionary[tp] = dataReader;
            }

            return this.dataReaderDictionary[tp];
        }

        private IDataReader CreateDataReader(Type type, string topicName)
        {
            var topic = this.defaultParticipant.CreateTopic(type, topicName);

            if (isLibraryApplied)
            {
                if (DataReaderQOSDic.ContainsKey(type))
                {
                    var dataReader = new DataReaderRx(defaultParticipant, topic, LibraryName, DataReaderQOSDic[type]);
                    return new DataReader(this, dataReader);

                }
                else
                {
                    var dataReader = new DataReaderRx(defaultParticipant, topic);
                    return new DataReader(this, dataReader);
                }
            }
            else
            {
                var dataReader = new DataReaderRx(defaultParticipant, topic);

                return new DataReader(this, dataReader);
            }

        }
        #endregion
    }
}

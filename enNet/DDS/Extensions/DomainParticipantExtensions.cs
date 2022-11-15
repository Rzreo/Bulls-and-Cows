using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;

namespace enNet
{
    /// <summary>
    /// DomainParticipant 확장 클래스
    /// </summary>
    public static class DomainParticipantExtensions
    {
        private static readonly Dictionary<int, Dictionary<string, Type>> Types = new Dictionary<int, Dictionary<string, Type>>();

        /// <summary>
        /// DomainParticipant 에 등록되어 있는 Type 을 반환
        /// </summary>
        /// <param name="participant">Domain ID</param>
        /// <param name="typeName">Type 이름</param>
        /// <returns>Type</returns>
        public static Type GetDataType(this DDS.DomainParticipant participant, string typeName)
        {
            var hashCode = participant.GetHashCode();
            if (Types.ContainsKey(hashCode) == false) return default;
            if (Types[hashCode].ContainsKey(typeName) == false) return default;
            return Types[hashCode][typeName];
        }

        /// <summary>
        /// DomainParticipant 에 Type 을 등록
        /// </summary>
        /// <param name="participant">등록에 사용될 DomainParticipant</param>
        /// <param name="type">등록할 RTI CONNEXT DDS 타입</param>
        /// <param name="typeName">등록에 사용될 타입 이름</param>
        public static void RegisterType(this DDS.DomainParticipant participant,
            Type type, string typeName = default)
        {
            if (!DDSTypeExtensions.IsDDSType(type)) throw new ArgumentException($"{type}");
            if (typeName == default) typeName = type.Name;

            try
            {
                var ts = DDSTypeExtensions.GetTypeSupport(type);
                var register_type = ts.GetMethod("register_type", BindingFlags.Public | BindingFlags.Static);
                register_type.Invoke(default, new object[] { participant, typeName });

                var hashCode = participant.GetHashCode();
                if (!Types.ContainsKey(hashCode)) Types[hashCode] = new Dictionary<string, Type>();
                Types[hashCode][typeName] = type;
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
            }
        }

        /// <summary>
        /// Topic 생성
        /// </summary>
        /// <param name="participant">Topic 생성에 사용될 DomainParticipant</param>
        /// <param name="type">Topic 생성에 사용할 타입</param>
        /// <param name="topicName">생성할 Topic 의 이름</param>
        /// <returns>Topic</returns>
        public static DDS.Topic CreateTopic(this DDS.DomainParticipant participant,
            Type type, string topicName = default)
        {
            if (!DDSTypeExtensions.IsDDSType(type)) return default;
            if (topicName == default) topicName = type.Name;

            try
            {
                var timeout = DDS.Duration_t.DURATION_ZERO;
                var topic = participant.find_topic(topicName, ref timeout);
                if (topic != default) return topic;

                participant.RegisterType(type, type.Name);

                return participant.create_topic(
                    topicName, type.Name,
                    DDS.DomainParticipant.TOPIC_QOS_DEFAULT,
                    default,
                    DDS.StatusMask.STATUS_MASK_NONE);
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
                return default;
            }
        }

        /// <summary>
        /// Publisher 생성
        /// </summary>
        /// <param name="participant">Publisher 생성에 사용될 DomainParticipant</param>
        /// <returns>Publisher</returns>
        public static DDS.Publisher CreatePublisher(this DDS.DomainParticipant participant)
        {
            return participant.create_publisher(
                DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT,
                default,
                DDS.StatusMask.STATUS_MASK_NONE);
        }

        /// <summary>
        /// Subscriber 생성
        /// </summary>
        /// <param name="participant">Subscriber 생성에 사용될 DomainParticipant</param>
        /// <returns>Subscriber</returns>
        public static DDS.Subscriber CreateSubscriber(this DDS.DomainParticipant participant)
        {
            return participant.create_subscriber(
                DDS.DomainParticipant.SUBSCRIBER_QOS_DEFAULT,
                default,
                DDS.StatusMask.STATUS_MASK_NONE);
        }

        /// <summary>
        /// DomainParticipant 에서 관리하는 DataWriter 생성
        /// </summary>
        /// <param name="participant">DataWriter 생성에 사용될 DomainParticipant</param>
        /// <param name="topic">DataWriter 생성에 사용될 Topic</param>
        /// <returns>DataWriter</returns>
        public static DDS.DataWriter CreateDataWriter(this DDS.DomainParticipant participant,
            DDS.Topic topic)
        {
            return participant.create_datawriter(
                topic,
                DDS.Publisher.DATAWRITER_QOS_DEFAULT,
                default,
                DDS.StatusMask.STATUS_MASK_NONE);
        }

        /// <summary>
        /// DomainParticipant 에서 관리하는 QOS 를 적용한 DataWriter 생성
        /// </summary>
        /// <param name="participant">DataWriter 생성에 사용될 DomainParticipant</param>
        /// <param name="topic">DataWriter 생성에 사용될 Topic</param>
        /// <param name="libraryName">QOS Library Name</param>
        /// <param name="profileName">QOS Profile Name</param>
        /// <returns>DataWriter</returns>
        public static DDS.DataWriter CreateDataWriterWithProfile(this DDS.DomainParticipant participant,
            DDS.Topic topic, string libraryName, string profileName)
        {
            try
            {
                return participant.create_datawriter_with_profile(
                    topic,
                    libraryName,
                    profileName,
                    default,
                    DDS.StatusMask.STATUS_MASK_ALL);
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
                return default;
            }
        }

        /// <summary>
        /// DataReader 생성
        /// </summary>
        /// <param name="participant">DataReader 생성에 사용될 DomainParticipant</param>
        /// <param name="topic">DataReader 생성에 사용될 Topic</param>
        /// <param name="listener">DataReaderListener</param>
        /// <returns>DataReader</returns>
        public static DDS.DataReader CreateDataReader(this DDS.DomainParticipant participant,
            DDS.ITopicDescription topic, DDS.DataReaderListener listener)
        {
            try
            {
                return participant.create_datareader(
                    topic,
                    DDS.Subscriber.DATAREADER_QOS_DEFAULT,
                    listener,
                    DDS.StatusMask.STATUS_MASK_ALL);
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
                return default;
            }
        }

        /// <summary>
        /// QOS 를 적용한 DataReader 생성
        /// </summary>
        /// <param name="participant">DataReader 생성에 사용될 DomainParticipant</param>
        /// <param name="topic">DataReader 생성에 사용될 Topic</param>
        /// <param name="libraryName">QOS Library Name</param>
        /// <param name="profileName">QOS Profile Name</param>
        /// <param name="listener">DataReaderListener</param>
        /// <returns>DataReader</returns>
        public static DDS.DataReader CreateDataReaderWithProfile(this DDS.DomainParticipant participant,
            DDS.ITopicDescription topic, string libraryName, string profileName, DDS.DataReaderListener listener)
        {
            try
            {
                return participant.create_datareader_with_profile(
                    topic,
                    libraryName,
                    profileName,
                    listener,
                    DDS.StatusMask.STATUS_MASK_ALL);
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
                return default;
            }
        }

        /// <summary>
        /// DataReaderRx 생성
        /// </summary>
        /// <param name="participant">DataReaderRx 생성에 사용될 DomainParticipant</param>
        /// <param name="topic">DataReaderRx 생성에 사용될 Topic</param>
        /// <param name="libraryName">QOS Library Name</param>
        /// <param name="profileName">QOS Profile Name</param>
        /// <returns>DataReaderRx</returns>
        public static DataReaderRx CreateDataReaderRx(this DDS.DomainParticipant participant,
           DDS.Topic topic, string libraryName = default, string profileName = default)
        {
            return new DataReaderRx(participant, topic, libraryName, profileName);
        }
    }
}
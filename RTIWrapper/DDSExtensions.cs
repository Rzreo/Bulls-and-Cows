using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RTIWrapper
{
    public static class DomainParticipantFactoryExtensions
    {
        public static DDS.DomainParticipant CreateParticipant(
            this DDS.DomainParticipantFactory domainParticipantFactory,
            int domainId)
        {
            try
            {
                return domainParticipantFactory.create_participant(
                    domainId,
                    DDS.DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                    default,
                    DDS.StatusMask.STATUS_MASK_NONE);
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
    }
    public static class DomainParticipantExtensions
    {
        /// <summary>
        /// Domain - Typename => Type
        /// </summary>
        private static readonly Dictionary<int, Dictionary<string, Type>> Types = new Dictionary<int, Dictionary<string, Type>>();

        /// <summary>
        /// DomainParticipant 에 등록되어 있는 Type 을 반환.
        /// </summary>
        /// <param name="participant">Domain ID.</param>
        /// <param name="typeName">Type 이름.</param>
        /// <returns>Type.</returns>
        public static Type GetDataType(this DDS.DomainParticipant participant, string typeName)
        {
            var hashCode = participant.GetHashCode();
            if (Types.ContainsKey(hashCode) == false)
            {
                return default;
            }

            if (Types[hashCode].ContainsKey(typeName) == false)
            {
                return default;
            }

            return Types[hashCode][typeName];
        }
        public static DDS.Publisher CreatePublisher(this DDS.DomainParticipant participant)
        {
            return participant.create_publisher(
                DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT,
                default,
                DDS.StatusMask.STATUS_MASK_NONE);
        }
        public static DDS.Subscriber CreateSubscriber(this DDS.DomainParticipant participant)
        {
            return participant.create_subscriber(
                DDS.DomainParticipant.SUBSCRIBER_QOS_DEFAULT,
                default,
                DDS.StatusMask.STATUS_MASK_NONE);
        }
        public static DDS.Topic CreateTopic(this DDS.DomainParticipant participant, Type type, string topicName = default)
        {
            if (!DDSTypeExtensions.IsDDSType(type))
            {
                return default;
            }

            if (topicName == default)
            {
                topicName = type.Name;
            }

            try
            {
                var timeout = DDS.Duration_t.DURATION_ZERO;
                var topic = participant.find_topic(topicName, ref timeout);
                if (topic != default)
                {
                    return topic;
                }

                participant.RegisterType(type, type.Name);

                return participant.create_topic(
                    topicName,
                    type.Name,
                    DDS.DomainParticipant.TOPIC_QOS_DEFAULT,
                    default,
                    DDS.StatusMask.STATUS_MASK_NONE);
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
        public static void RegisterType(this DDS.DomainParticipant participant, Type type, string typeName = default)
        {
            if (!DDSTypeExtensions.IsDDSType(type))
            {
                throw new ArgumentException($"{type}");
            }

            if (typeName == default)
            {
                typeName = type.Name;
            }

            try
            {
                var ts = DDSTypeExtensions.GetTypeSupport(type);
                var register_type = ts.GetMethod("register_type", System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.Static);
                register_type.Invoke(default, new object[] { participant, typeName });

                var hashCode = participant.GetHashCode();
                if (!Types.ContainsKey(hashCode))
                {
                    Types[hashCode] = new Dictionary<string, Type>();
                }

                Types[hashCode][typeName] = type;
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e);
            }
        }

        public static DDS.DataReader CreateDataReader(this DDS.DomainParticipant participant, DDS.ITopicDescription topic, DDS.DataReaderListener listener)
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
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
        public static DDS.DataReader CreateDataReaderWithProfile(this DDS.DomainParticipant participant, DDS.ITopicDescription topic, string libraryName, string profileName, DDS.DataReaderListener listener)
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
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
    }
    public static class TopicExtensions
    {
        public static Type GetDataType(this DDS.Topic topic)
        {
            return topic.get_participant().GetDataType(topic.get_type_name());
        }
    }
    public static class DataWriterExtensions
    {
        public static void Write(this DDS.DataWriter dataWriter, object data)
        {
            dataWriter.write_untyped(data, ref DDS.InstanceHandle_t.HANDLE_NIL);
        }
        public static Type GetDataType(this DDS.DataWriter dataWriter)
        {
            return dataWriter.get_topic().GetDataType();
        }
    }
}

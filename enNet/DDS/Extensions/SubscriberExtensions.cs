using System;
using System.Diagnostics;

namespace enNet
{
    /// <summary>
    /// Subscriber 확장 클래스
    /// </summary>
    public static class SubscriberExtensions
    {
        /// <summary>
        /// DataReader 생성
        /// </summary>
        /// <param name="subscriber">DataReader 생성에 사용될 Subscriber</param>
        /// <param name="topic">DataReader 생성에 사용될 Topic</param>
        /// <param name="listener">DataReaderListener</param>
        /// <returns>DataReader</returns>
        public static DDS.DataReader CreateDataReader(this DDS.Subscriber subscriber,
            DDS.ITopicDescription topic, DDS.DataReaderListener listener)
        {
            try
            {
                return subscriber.create_datareader(
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
        /// <param name="subscriber">DataReader 생성에 사용될 Subscriber</param>
        /// <param name="topic">DataReader 생성에 사용될 Topic</param>
        /// <param name="libraryName">QOS Library Name</param>
        /// <param name="profileName">QOS Profile Name</param>
        /// <param name="listener">DataReaderListener</param>
        /// <returns>DataReader</returns>
        public static DDS.DataReader CreateDataReaderWithProfile(this DDS.Subscriber subscriber,
            DDS.ITopicDescription topic, string libraryName, string profileName, DDS.DataReaderListener listener)
        {
            try
            {
                return subscriber.create_datareader_with_profile(
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
        /// Object Type 의 DataReaderRx 생성
        /// </summary>
        /// <param name="subscriber">DataReader 생성에 사용될 Subscriber</param>
        /// <param name="topic">DataReader 생성에 사용될 Topic</param>
        /// <returns>DataReaderRx</returns>
        public static DataReaderRx CreateDataReaderRx(this DDS.Subscriber subscriber,
            DDS.Topic topic, string libraryName = default, string profileName = default)
        {
            return new DataReaderRx(subscriber, topic, libraryName, profileName);
        }
    }
}
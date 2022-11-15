using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RTIWrapper
{
    public static class PublisherExtensions
    {
        public static DDS.DataWriter CreateDataWriter(this DDS.Publisher publisher, DDS.Topic topic)
        {
            try
            {
                return publisher.create_datawriter(
                    topic,
                    DDS.Publisher.DATAWRITER_QOS_DEFAULT,
                    default,
                    DDS.StatusMask.STATUS_MASK_ALL);
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }

        /// <summary>
        /// QOS 를 적용한 DataWriter 생성.
        /// </summary>
        /// <param name="publisher">DataWriter 생성에 사용될 Publisher.</param>
        /// <param name="topic">DataWriter 생성에 사용될 Topic.</param>
        /// <param name="libraryName">QOS Library Name.</param>
        /// <param name="profileName">QOS Profile Name.</param>
        /// <returns>DataWriter.</returns>
        public static DDS.DataWriter CreateDataWriterWithProfile(
            this DDS.Publisher publisher,
            DDS.Topic topic,
            string libraryName,
            string profileName)
        {
            try
            {
                return publisher.create_datawriter_with_profile(
                    topic,
                    libraryName,
                    profileName,
                    default,
                    DDS.StatusMask.STATUS_MASK_ALL);
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RTIWrapper
{
    public static class SubscriberExtensions
    {
        public static DDS.DataReader CreateDataReader(this DDS.Subscriber subscriber, DDS.ITopicDescription topic, DDS.DataReaderListener listener)
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
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
        public static DDS.DataReader CreateDataReaderWithProfile(
            this DDS.Subscriber subscriber,
            DDS.ITopicDescription topic,
            string libraryName,
            string profileName,
            DDS.DataReaderListener listener)
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
                System.Diagnostics.Debug.WriteLine(e);
                return default;
            }
        }
    }
}

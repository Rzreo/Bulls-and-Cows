using System;

namespace enNet
{
    public static class DataReaderRxExtensions
    {
        public static DataReaderRx<T> Cast<T>(this DataReaderRx dataReaderRx)
        {
            return new DataReaderRx<T>(dataReaderRx);
        }

        public static Type GetDataType(this DataReaderRx dataReader)
        {
            return dataReader.Topic.GetDataType();
        }
    }
}
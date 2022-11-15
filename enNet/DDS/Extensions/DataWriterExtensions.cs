using System;

namespace enNet
{
    /// <summary>
    /// DataWriter 의 확장 클래스
    /// </summary>
    public static class DataWriterExtensions
    {
        /// <summary>
        /// DataWriter 를 사용하여 object 형태의 sample 를 전송
        /// </summary>
        /// <param name="dataWriter">전송에 사용될 DataWriter</param>
        /// <param name="data">object 형태의 RTI DDS 로 정의된 Data</param>
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
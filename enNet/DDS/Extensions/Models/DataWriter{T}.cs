using System;

namespace enNet
{
    /// <summary>
    /// Generic 형태의 DataWriter
    /// </summary>
    /// <typeparam name="T">DataWriter 의 Topic Data Type</typeparam>
    public class DataWriter<T>
    {
        private readonly DDS.DataWriter dataWriter;

        public DataWriter(DDS.DataWriter dataWriter)
        {
            this.dataWriter = dataWriter ?? throw new ArgumentNullException(nameof(dataWriter));
            if (!(this.dataWriter.GetDataType() == typeof(T))) throw new InvalidOperationException(nameof(T));
        }

        public void Write(T sample)
        {
            this.dataWriter.Write(sample);
        }
    }
}
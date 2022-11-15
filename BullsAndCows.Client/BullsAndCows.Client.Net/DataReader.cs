namespace BullsAndCows.Client.Net
{
    using System;
    using System.Linq;
    using System.Reactive.Linq;
    using RTIWrapper;

    public interface IDataReader
    {
        IObservable<object> Samples { get; }
        void Dispose();
    }
    public class DataReader : IDataReader
    {
        private readonly IDataReaderRx dataReader;
        private readonly DDSManager ddsService;
        public DataReader(DDSManager ddsService, IDataReaderRx dataReader)
        {
            this.ddsService = ddsService;
            this.dataReader = dataReader;
        }
        public IObservable<object> Samples => this.dataReader.Samples.Where(_ => this.ddsService.IsEnabled);
        public void Dispose()
        {
            if (this.dataReader != null)
            {
                this.dataReader.Dispose();
            }
        }
    }
}

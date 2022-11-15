namespace BullsAndCows.Server.Net
{
    using RTIWrapper;
    using System;
    using System.Collections.Generic;
    using System.Data;
    using System.Linq;
    using System.Reactive.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public interface IDataReader
    {
        IObservable<object> Samples { get; }
        void Dispose();
    }

    public class DataReader : IDataReader
    {
        private DDSManager ddsService;
        private IDataReaderRx dataReader;

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

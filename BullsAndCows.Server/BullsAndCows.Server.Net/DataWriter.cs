namespace BullsAndCows.Server.Net
{
    using RTIWrapper;
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public class DataWriter : IDataWriter
    {
        private DDSManager ddsService;
        private DDS.DataWriter dataWriter;

        public DataWriter(DDSManager ddsService, DDS.DataWriter dataWriter)
        {
            this.ddsService = ddsService;
            this.dataWriter = dataWriter;

        }

        public void Write(object sample)
        {
            if (!ddsService.IsEnabled) return;
            this.dataWriter.Write(sample);
        }
    }
}

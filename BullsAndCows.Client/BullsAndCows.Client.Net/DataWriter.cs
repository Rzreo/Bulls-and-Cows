using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Net
{
    using RTIWrapper;
    public class DataWriter : IDataWriter
    {
        private readonly DDS.DataWriter dataWriter;
        private readonly DDSManager ddsService;
        private readonly PostProcessing postProcessing;
        public DataWriter(DDSManager ddsService, DDS.DataWriter dataWriter, PostProcessing postProcessing)
        {
            this.ddsService = ddsService;
            this.dataWriter = dataWriter;
            this.postProcessing = postProcessing;
        }
        public void Write(object sample)
        {
            if (!this.ddsService.IsEnabled)
            {
                return;
            }

            //this.postProcessing.Handle(sample);
            this.dataWriter.Write(sample);

        }
    }
}

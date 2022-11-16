namespace BullsAndCows.Server.Net
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public partial class DDSManager
    {
        private const string RDReader = "LSAM_DDS_DataReader_DURABILITY_Profile";
        private const string RDWriter = "LSAM_DDS_DataWriter_DURABILITY_Profile";

        private const string RReader = "chocolate_factory_Profile";
        private const string RWriter = "chocolate_factory_Profile";


        public Dictionary<Type, string> DataWriterQoSDic { get; }

        public Dictionary<Type, string> DataReaderQOSDic { get; }


        private static Dictionary<Type, string> BuildDataReaderQOS()
        {
            var temp = new Dictionary<Type, string>();

            temp.Add(typeof(BAC_CONNECT_INIT_MESSAGE), RReader); //  추가
            temp.Add(typeof(BAC_CONNECT_MESSAGE), RReader); //  추가

            return temp;
        }

        private static Dictionary<Type, string> BuildDataWriterQOS()
        {
            var temp = new Dictionary<Type, string>();

            temp.Add(typeof(BAC_CONNECT_INIT_MESSAGE), RWriter); //  추가
            temp.Add(typeof(BAC_CONNECT_MESSAGE), RWriter); //  추가

            return temp;
        }

    }
}

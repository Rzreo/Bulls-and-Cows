using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.Net
{
    public partial class DDSManager
    {    

        private const string RReader = "chocolate_factory_Profile";
        private const string RWriter = "chocolate_factory_Profile";
        public Dictionary<Type, string> DataReaderQOSDic { get; }
        public Dictionary<Type, string> DataWriterQoSDic { get; }
        private static Dictionary<Type, string> BuildDataReaderQOS()
        {
            var temp = new Dictionary<Type, string>();

            temp.Add(typeof(BAC_CONNECT_INIT_MESSAGE), RReader);
            temp.Add(typeof(BAC_CONNECT_MESSAGE), RReader);

            return temp;
        }
        private static Dictionary<Type, string> BuildDataWriterQOS()
        {
            var temp = new Dictionary<Type, string>();

            temp.Add(typeof(BAC_CONNECT_INIT_MESSAGE), RWriter);
            temp.Add(typeof(BAC_CONNECT_MESSAGE), RWriter);

            return temp;
        }
    }
}

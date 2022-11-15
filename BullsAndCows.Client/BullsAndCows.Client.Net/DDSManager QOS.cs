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

            temp.Add(typeof(BAC_CREATE_ROOM), RReader);
            temp.Add(typeof(Message), RReader);

            return temp;
        }
        private static Dictionary<Type, string> BuildDataWriterQOS()
        {
            var temp = new Dictionary<Type, string>();

            temp.Add(typeof(BAC_CREATE_ROOM), RWriter);
            temp.Add(typeof(Message), RWriter);

            return temp;
        }
    }
}

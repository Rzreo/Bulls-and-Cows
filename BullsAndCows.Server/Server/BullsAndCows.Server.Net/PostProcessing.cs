namespace BullsAndCows.Server.Net
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public class PostProcessing
    {
        private int domainID;

        private Dictionary<Type, (byte, byte)> Labels;
        private byte ComputerID;
        public PostProcessing(int domainID, Dictionary<Type, (byte Item1, byte Item2)> label, byte computerID)
        {
            this.domainID = domainID;
            this.Labels = label;
            this.ComputerID = computerID;
        }
    }
}

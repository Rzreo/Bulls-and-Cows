using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Infrastructure
{
    public struct BAC_ROOM_DATA
    {
        public UInt32 RoomID { get; set; }
        public UInt32 Max_Num_Participants;
        public UInt32 Cur_Num_Participants;
    };
    public struct BAC_PARTICIPANT_DATA
    {
        public string ClientID { get; set; }
    };
}

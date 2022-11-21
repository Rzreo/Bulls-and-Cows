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
    public struct BAC_GAME_INPUT_DATA
    {
        public int A;
        public int B;
        public int C;
    };
    public struct BAC_GAME_OUTPUT_DATA
    {
        public int nStrike;
        public int nBall;
        public int nOut;
    };
    public struct BAC_GAME_RESULT_DATA
    {
        public string WinnerClientID;
        public string TryCount;
    };
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Infrastructure.Utils.Regions
{
    /// <summary>
    /// 얘 왜 Defines.RegionNames 에도 있고 그럼?
    /// </summary>
    public static class ClientRegions
    {
        public const string MainRegion = "MainRegion";

        public const string Lobby_PART1 = "Lobby_PART1";
        public const string Lobby_PART2 = "Lobby_PART2";

        public const string Waiting_ParticipantsListRegion = "Waiting_ParticipantsListRegion";

        public const string Play_PlayRegion = "Play_PlayRegion";
        public const string Play_InputRegion = "Play_InputRegion";
    }
}

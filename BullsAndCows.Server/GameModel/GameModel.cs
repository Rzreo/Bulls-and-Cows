using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameModel
{
    using BullsAndCows.Infrastructure;

    public class PrivateDetail
    {
        public List<string> History { get; set; }
        public string BeforeNum { get; set; }
        public int TryCount { get; set; }
    }
    public class RoomDetail
    {
        public string CorrectNum { get; set; }
        public Dictionary<string,PrivateDetail> Clients { get; set; }
    }
    public class GameModel
    {
        public Dictionary<int, RoomDetail> RoomInfo { get; set; }

        public GameModel()
        {
            RoomInfo= new Dictionary<int, RoomDetail>();
        }

        public void GameStart(int roomId, List<string> clients)
        {
            Random rand = new Random(Guid.NewGuid().GetHashCode());
            List<int> numList = new List<int>();
            for (int i = 0; i < 10; i++)
            {
                numList.Add(i);
            }
            string str = "";
            for (int i = 0; i < 3; i++)
            {
                int index = rand.Next(0, 10 - i);
                str += numList[index];
                numList.RemoveAt(index);
            }

            Dictionary<string,PrivateDetail> pds = new Dictionary<string,PrivateDetail>();
            foreach (string cid in clients)
            {
                PrivateDetail pd = new PrivateDetail() {TryCount = 0, BeforeNum = "", History = new List<string>() };
                pds.Add(cid,pd);
            }
            RoomDetail rd = new RoomDetail() { CorrectNum = str, Clients= pds };
            RoomInfo.Add(roomId, rd);
        }

        public BAC_GAME_OUTPUT_DATA CountResult(int roomId, string clientId, string input)
        {
            BAC_GAME_OUTPUT_DATA gameOutput = new BAC_GAME_OUTPUT_DATA() { nStrike = -1, nBall = -1, nOut = -1, tryCount = 0 };
            if (!RoomInfo.ContainsKey(roomId)) return gameOutput;
            if (!RoomInfo[roomId].Clients.ContainsKey(clientId)) return gameOutput;

            RoomInfo[roomId].Clients[clientId].BeforeNum = input;
            int tryCnt = RoomInfo[roomId].Clients[clientId].TryCount + 1;
            string num = RoomInfo[roomId].CorrectNum;
            int s = 0, b = 0, o = 0;
            for (int i = 0; i < 3; i++)
            {
                if (num[i] == input[i]) s++;
                else if (num.Contains(input[i])) b++;
                else o++;
            }
            RoomInfo[roomId].Clients[clientId].History.Add($"\n시도횟수:{tryCnt}  입력숫자:{input}  S:{s} B:{b} O:{o}");
            gameOutput = new BAC_GAME_OUTPUT_DATA() { nStrike=s, nBall=b ,nOut=o, tryCount = tryCnt };
            return gameOutput;
        }
    }
}

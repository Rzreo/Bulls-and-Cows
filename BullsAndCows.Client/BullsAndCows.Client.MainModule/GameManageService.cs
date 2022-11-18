using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Client.MainModule
{
    using BullsAndCows.Infrastructure.ClientServices;
    using BullsAndCows.Infrastructure.Utils.Regions;
    using Prism.Regions;

    class GameManageService : IGameManageService
    {
        IRegionManager _regionMgr;
        public GameManageService(IRegionManager regionMgr)
        {
            this._regionMgr = regionMgr;
        }

        public void GoToLobby()
        {
            _regionMgr.RequestNavigate(ClientRegions.MainRegion, "LobbyFrame");
        }
        public void GoToWaitting()
        {
            _regionMgr.RequestNavigate(ClientRegions.MainRegion, "WaitingFrame");
        }
        public void GoToPlaying()
        {
            _regionMgr.RequestNavigate(ClientRegions.MainRegion, "PlayFrame");
        }
    }
}

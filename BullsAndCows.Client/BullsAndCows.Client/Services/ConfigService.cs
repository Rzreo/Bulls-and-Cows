using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace BullsAndCows.Client.Services
{
    using BullsAndCows.Infrastructure.BaseClass;
    using BullsAndCows.Infrastructure.OperationManagement;
    using BullsAndCows.Infrastructure.Utils;
    public class ConfigService : DisposableService, IConfigService
    {
        public ConfigService()
        {
            var baseInfo = IniParser.Parse($"{AppDomain.CurrentDomain.BaseDirectory}../Config/config.ini");
        }
    }
}

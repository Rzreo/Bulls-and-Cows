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
    using Reactive.Bindings;
    using Reactive.Bindings.Extensions;

    public class ConfigService : DisposableService, IConfigService
    {
        public ConfigService()
        {
            var baseInfo = IniParser.Parse($"{AppDomain.CurrentDomain.BaseDirectory}../Config/config.ini");
            var computerNumber = baseInfo["OCC"]["COMPUTER_NUMBER"];
            this.ComputerNumber = new ReactiveProperty<int>(int.Parse(computerNumber));
            this.ComputerNumber.AddTo(this.Disposables);
            this.ProcessID = new ReactiveProperty<int>(System.Diagnostics.Process.GetCurrentProcess().Id);
        }

        public ReactiveProperty<int> ComputerNumber { get; } = new ReactiveProperty<int>();
        public ReactiveProperty<int> ProcessID { get; } = new ReactiveProperty<int>();
    }
}

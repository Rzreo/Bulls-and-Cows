namespace BullsAndCows.Infrastructure.Utils
{
    using BullsAndCows.Infrastructure.OperationManagement;
    static public class IConfigServiceExtension
    {
        public static string ClientID(this IConfigService config)
        {
            return $"{config.ComputerNumber.Value}-{config.ProcessID.Value}";
        }
    }
}

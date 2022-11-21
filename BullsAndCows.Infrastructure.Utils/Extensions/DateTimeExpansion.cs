using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullsAndCows.Infrastructure.Utils
{
    public static class DateTimeExpansion
    {
        public static long ToMilli(this DateTime d)
        {
            return d.Ticks / TimeSpan.TicksPerMillisecond;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RTIWrapper
{
    public static class DDSTypeExtensions
    {
        private static readonly string KEYTYPESUPPORT = "TypeSupport";
        public static bool IsDDSType(this Type type)
        {
            return type.GetInterfaces()
                .Where(t => t.IsGenericType)
                .Any(t => t.GetGenericTypeDefinition() == typeof(DDS.ICopyable<>));
        }
        public static bool IsDDSType(this object sample)
        {
            return sample.GetType().IsDDSType();
        }
        public static Type GetTypeSupport(this Type type)
        {
            return type.Assembly.GetType(type.Name + KEYTYPESUPPORT);
        }
    }
}

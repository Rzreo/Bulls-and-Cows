using System;
using System.Linq;

namespace enNet
{
    /// <summary>
    /// RTI DDS Type 분석
    /// </summary>
    public static class DDSTypeExtensions
    {
        private static readonly string KEY_TYPE_SUPPORT = "TypeSupport";

        /// <summary>
        /// 입력받은 Type 이 RTI DDS Type 여부 확인
        /// </summary>
        /// <param name="type">분석 대상</param>
        /// <returns>RTI DDS Type 여부</returns>
        public static bool IsDDSType(this Type type)
        {
            return type.GetInterfaces()
                .Where(t => t.IsGenericType)
                .Any(t => t.GetGenericTypeDefinition() == typeof(DDS.ICopyable<>));
        }

        /// <summary>
        /// 입력받은 Type 이 RTI DDS Type 여부 확인
        /// </summary>
        /// <param name="type">분석 대상</param>
        /// <returns>RTI DDS Type 여부</returns>
        public static bool IsDDSType(this object sample)
        {
            return sample.GetType().GetInterfaces()
                .Where(t => t.IsGenericType)
                .Any(t => t.GetGenericTypeDefinition() == typeof(DDS.ICopyable<>));
        }

        /// <summary>
        /// RTI DDS Sequence Type 여부 확인
        /// </summary>
        /// <param name="type">분석 대상</param>
        /// <returns>Sequence Type 여부</returns>
        public static bool IsSequence(this Type type)
        {
            return typeof(DDS.ISequenceMarker).IsAssignableFrom(type);
        }

        /// <summary>
        /// RTI DDS StringWrapper Type 여부 확인
        /// </summary>
        /// <param name="type">분석 대상</param>
        /// <returns>StringWrapper 타입 여부</returns>
        public static bool IsStringWrapper(this Type type)
        {
            return type == typeof(DDS.StringWrapper);
        }

        /// <summary>
        /// 입력받은 Type 의 TypeSupport 를 반환
        /// </summary>
        /// <param name="type">분석 대상</param>
        /// <returns>TypeSupport</returns>
        public static Type GetTypeSupport(this Type type)
        {
            return type.Assembly.GetType(type.Name + KEY_TYPE_SUPPORT);
        }

        /// <summary>
        /// RTI DDS Sequence 의 Generic Argument Type (element type) 을 반환
        /// </summary>
        /// <param name="type">Sequence Type</param>
        /// <returns>element type</returns>
        public static Type GetSequenceGenericArgument(this Type type)
        {
            if (!typeof(DDS.ISequenceMarker).IsAssignableFrom(type)) return default;

            var tmpType = type;
            while (tmpType.BaseType != default)
            {
                tmpType = tmpType.BaseType;
                if (tmpType.IsGenericType && tmpType.GetGenericTypeDefinition() == typeof(DDS.Sequence<>))
                {
                    return tmpType.GetGenericArguments()[0];
                }
            }

            return default;
        }
    }
}
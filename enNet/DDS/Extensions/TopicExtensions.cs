using System;

namespace enNet
{
    /// <summary>
    /// Topic 확장 클래스
    /// </summary>
    public static class TopicExtensions
    {
        /// <summary>
        /// Topic 의 Type 정보를 반환
        /// </summary>
        /// <param name="topic">분석 대상</param>
        /// <returns>Type</returns>
        public static Type GetDataType(this DDS.Topic topic)
        {
            return topic.get_participant().GetDataType(topic.get_type_name());
        }
    }
}
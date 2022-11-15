using System;
using System.Diagnostics;

namespace enNet
{
    /// <summary>
    /// DomainParticipantFactory 확장 클래스
    /// </summary>
    public static class DomainParticipantFactoryExtensions
    {
        /// <summary>
        /// DomainParticipant 생성
        /// </summary>
        /// <param name="domainParticipantFactory">DomainParticipant 생성에 사용될 DomainParticipantFactory</param>
        /// <param name="domainId">Domain ID</param>
        /// <returns>DomainParticipant</returns>
        public static DDS.DomainParticipant CreateParticipant(
            this DDS.DomainParticipantFactory domainParticipantFactory,
            int domainId)
        {
            try
            {
                return domainParticipantFactory.create_participant(
                    domainId,
                    DDS.DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                    default,
                    DDS.StatusMask.STATUS_MASK_NONE);
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
                return default;
            }
        }

        /// <summary>
        /// QOS 를 적용한 DomainParticipant 생성
        /// </summary>
        /// <param name="domainParticipantFactory">DomainParticipant 생성에 사용될 DomainParticipantFactory</param>
        /// <param name="domainId">Domain ID</param>
        /// <param name="libraryName">QOS Library Name</param>
        /// <param name="profileName">QOS Profile Name</param>
        /// <returns>DomainParticipant</returns>
        public static DDS.DomainParticipant CreateParticipantWithProfile(
            this DDS.DomainParticipantFactory domainParticipantFactory,
            int domainId,
            string libraryName,
            string profileName)
        {
            try
            {
                return domainParticipantFactory.create_participant_with_profile(
                    domainId,
                    libraryName,
                    profileName,
                    default,
                    DDS.StatusMask.STATUS_MASK_NONE);
            }
            catch (Exception e)
            {
                Debug.WriteLine(e);
                return default;
            }
        }
    }
}
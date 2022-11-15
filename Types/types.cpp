
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from types.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma unmanaged
#include "ndds/ndds_cpp.h"
#pragma managed

using namespace System;
using namespace System::Collections;
using namespace DDS;

#include "types.h"

/* ========================================================================= */
Message::Message() {
    msg = "";
}

void Message::clear(){
    msg = "";
}

System::Boolean Message::copy_from(Message^ src) {

    Message^ dst = this;

    dst->msg = src->msg;
    return true;
}

Boolean Message::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    Message^ otherObj =
    dynamic_cast<Message^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (!msg->Equals(otherObj->msg)) {
        return false;
    }
    return true;
}

#ifndef NDDS_STANDALONE_TYPE
DDS::TypeCode^ Message::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(Message_get_typecode());
    }
    return _typecode;
}
#endif

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Message_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Message_g_tc_msg_string = DDS_INITIALIZE_STRING_TYPECODE((256));

    static DDS_TypeCode_Member Message_g_tc_members[1]=
    {

        {
            (char *)"msg",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Message_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Message", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            Message_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Message*/

    if (is_initialized) {
        return &Message_g_tc;
    }

    Message_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Message_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Message_g_tc_msg_string;

    /* Initialize the values for member annotations. */
    Message_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Message_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Message_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &Message_g_tc;
}
#endif
/* ========================================================================= */
Temperature::Temperature() {
    sensor_id = "";
    degrees = 0;
}

void Temperature::clear(){
    sensor_id = "";
    degrees = 0;
}

System::Boolean Temperature::copy_from(Temperature^ src) {

    Temperature^ dst = this;

    dst->sensor_id = src->sensor_id;
    dst->degrees = src->degrees;
    return true;
}

Boolean Temperature::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    Temperature^ otherObj =
    dynamic_cast<Temperature^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (!sensor_id->Equals(otherObj->sensor_id)) {
        return false;
    }
    if (degrees != otherObj->degrees) {
        return false;
    }
    return true;
}

#ifndef NDDS_STANDALONE_TYPE
DDS::TypeCode^ Temperature::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(Temperature_get_typecode());
    }
    return _typecode;
}
#endif

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Temperature_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Temperature_g_tc_sensor_id_string = DDS_INITIALIZE_STRING_TYPECODE(((MAX_STRING_LEN::VALUE)));

    static DDS_TypeCode_Member Temperature_g_tc_members[2]=
    {

        {
            (char *)"sensor_id",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"degrees",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Temperature_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Temperature", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Temperature_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Temperature*/

    if (is_initialized) {
        return &Temperature_g_tc;
    }

    Temperature_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Temperature_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Temperature_g_tc_sensor_id_string;
    Temperature_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    /* Initialize the values for member annotations. */
    Temperature_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Temperature_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Temperature_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Temperature_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    Temperature_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Temperature_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Temperature_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Temperature_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Temperature_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &Temperature_g_tc;
}
#endif

StationKind StationKind_get_default_value() {
    return StationKindHelper::StationKind_get_default_value();
}

StationKind StationKindHelper::StationKind_get_default_value() {
    return StationKind::INVALID_CONTROLLER;
}
#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* StationKind_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member StationKind_g_tc_members[6]=
    {

        {
            (char *)"INVALID_CONTROLLER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)StationKind::INVALID_CONTROLLER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"COCOA_BUTTER_CONTROLLER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)StationKind::COCOA_BUTTER_CONTROLLER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"SUGAR_CONTROLLER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)StationKind::SUGAR_CONTROLLER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"MILK_CONTROLLER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)StationKind::MILK_CONTROLLER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"VANILLA_CONTROLLER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)StationKind::VANILLA_CONTROLLER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"TEMPERING_CONTROLLER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)StationKind::TEMPERING_CONTROLLER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode StationKind_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"StationKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            StationKind_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for StationKind*/

    if (is_initialized) {
        return &StationKind_g_tc;
    }

    StationKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    StationKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    StationKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

    StationKind_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &StationKind_g_tc;
}
#endif

LotStatusKind LotStatusKind_get_default_value() {
    return LotStatusKindHelper::LotStatusKind_get_default_value();
}

LotStatusKind LotStatusKindHelper::LotStatusKind_get_default_value() {
    return LotStatusKind::WAITING;
}
#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* LotStatusKind_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member LotStatusKind_g_tc_members[3]=
    {

        {
            (char *)"WAITING",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)LotStatusKind::WAITING, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"PROCESSING",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)LotStatusKind::PROCESSING, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"COMPLETED",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)LotStatusKind::COMPLETED, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode LotStatusKind_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"LotStatusKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            LotStatusKind_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for LotStatusKind*/

    if (is_initialized) {
        return &LotStatusKind_g_tc;
    }

    LotStatusKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    LotStatusKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    LotStatusKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

    LotStatusKind_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &LotStatusKind_g_tc;
}
#endif
/* ========================================================================= */
ChocolateLotState::ChocolateLotState() {
    lot_id = 0;
    station = StationKind::INVALID_CONTROLLER;
    next_station = StationKind::INVALID_CONTROLLER;
    lot_status = LotStatusKind::WAITING;
}

void ChocolateLotState::clear(){
    lot_id = 0;
    station = StationKind::INVALID_CONTROLLER;
    next_station = StationKind::INVALID_CONTROLLER;
    lot_status = LotStatusKind::WAITING;
}

System::Boolean ChocolateLotState::copy_from(ChocolateLotState^ src) {

    ChocolateLotState^ dst = this;

    dst->lot_id = src->lot_id;
    dst->station = src->station;
    dst->next_station = src->next_station;
    dst->lot_status = src->lot_status;
    return true;
}

Boolean ChocolateLotState::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    ChocolateLotState^ otherObj =
    dynamic_cast<ChocolateLotState^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (lot_id != otherObj->lot_id) {
        return false;
    }
    if (station != otherObj->station) {
        return false;
    }
    if (next_station != otherObj->next_station) {
        return false;
    }
    if (lot_status != otherObj->lot_status) {
        return false;
    }
    return true;
}

#ifndef NDDS_STANDALONE_TYPE
DDS::TypeCode^ ChocolateLotState::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(ChocolateLotState_get_typecode());
    }
    return _typecode;
}
#endif

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ChocolateLotState_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ChocolateLotState_g_tc_members[4]=
    {

        {
            (char *)"lot_id",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"station",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"next_station",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"lot_status",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ChocolateLotState_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ChocolateLotState", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ChocolateLotState_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ChocolateLotState*/

    if (is_initialized) {
        return &ChocolateLotState_g_tc;
    }

    ChocolateLotState_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ChocolateLotState_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    ChocolateLotState_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)StationKind_get_typecode();
    ChocolateLotState_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)StationKind_get_typecode();
    ChocolateLotState_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)LotStatusKind_get_typecode();

    /* Initialize the values for member annotations. */
    ChocolateLotState_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    ChocolateLotState_g_tc_members[0]._annotations._defaultValue._u.ulong_value = 0u;
    ChocolateLotState_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    ChocolateLotState_g_tc_members[0]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    ChocolateLotState_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    ChocolateLotState_g_tc_members[0]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    ChocolateLotState_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ChocolateLotState_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

    ChocolateLotState_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ChocolateLotState_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;

    ChocolateLotState_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ChocolateLotState_g_tc_members[3]._annotations._defaultValue._u.enumerated_value = 0;

    ChocolateLotState_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &ChocolateLotState_g_tc;
}
#endif


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
BAC_CONNECT_INIT_MESSAGE::BAC_CONNECT_INIT_MESSAGE() {
    CLIENT_ID = "";
}

void BAC_CONNECT_INIT_MESSAGE::clear(){
    CLIENT_ID = "";
}

System::Boolean BAC_CONNECT_INIT_MESSAGE::copy_from(BAC_CONNECT_INIT_MESSAGE^ src) {

    BAC_CONNECT_INIT_MESSAGE^ dst = this;

    dst->CLIENT_ID = src->CLIENT_ID;
    return true;
}

Boolean BAC_CONNECT_INIT_MESSAGE::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    BAC_CONNECT_INIT_MESSAGE^ otherObj =
    dynamic_cast<BAC_CONNECT_INIT_MESSAGE^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (!CLIENT_ID->Equals(otherObj->CLIENT_ID)) {
        return false;
    }
    return true;
}

#ifndef NDDS_STANDALONE_TYPE
DDS::TypeCode^ BAC_CONNECT_INIT_MESSAGE::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(BAC_CONNECT_INIT_MESSAGE_get_typecode());
    }
    return _typecode;
}
#endif

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* BAC_CONNECT_INIT_MESSAGE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode BAC_CONNECT_INIT_MESSAGE_g_tc_CLIENT_ID_string = DDS_INITIALIZE_STRING_TYPECODE(((ID_STRING_LEN::VALUE)));

    static DDS_TypeCode_Member BAC_CONNECT_INIT_MESSAGE_g_tc_members[1]=
    {

        {
            (char *)"CLIENT_ID",/* Member name */
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

    static DDS_TypeCode BAC_CONNECT_INIT_MESSAGE_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"BAC_CONNECT_INIT_MESSAGE", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            BAC_CONNECT_INIT_MESSAGE_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for BAC_CONNECT_INIT_MESSAGE*/

    if (is_initialized) {
        return &BAC_CONNECT_INIT_MESSAGE_g_tc;
    }

    BAC_CONNECT_INIT_MESSAGE_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    BAC_CONNECT_INIT_MESSAGE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&BAC_CONNECT_INIT_MESSAGE_g_tc_CLIENT_ID_string;

    /* Initialize the values for member annotations. */
    BAC_CONNECT_INIT_MESSAGE_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    BAC_CONNECT_INIT_MESSAGE_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    BAC_CONNECT_INIT_MESSAGE_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &BAC_CONNECT_INIT_MESSAGE_g_tc;
}
#endif

CLIENT_CONNECT_MESSAGE_TYPE CLIENT_CONNECT_MESSAGE_TYPE_get_default_value() {
    return CLIENT_CONNECT_MESSAGE_TYPEHelper::CLIENT_CONNECT_MESSAGE_TYPE_get_default_value();
}

CLIENT_CONNECT_MESSAGE_TYPE CLIENT_CONNECT_MESSAGE_TYPEHelper::CLIENT_CONNECT_MESSAGE_TYPE_get_default_value() {
    return CLIENT_CONNECT_MESSAGE_TYPE::SERVER_CONNECT_SUCCESS;
}
#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* CLIENT_CONNECT_MESSAGE_TYPE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member CLIENT_CONNECT_MESSAGE_TYPE_g_tc_members[1]=
    {

        {
            (char *)"SERVER_CONNECT_SUCCESS",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            (RTICdrLong)CLIENT_CONNECT_MESSAGE_TYPE::SERVER_CONNECT_SUCCESS, 
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

    static DDS_TypeCode CLIENT_CONNECT_MESSAGE_TYPE_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"CLIENT_CONNECT_MESSAGE_TYPE", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            CLIENT_CONNECT_MESSAGE_TYPE_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for CLIENT_CONNECT_MESSAGE_TYPE*/

    if (is_initialized) {
        return &CLIENT_CONNECT_MESSAGE_TYPE_g_tc;
    }

    CLIENT_CONNECT_MESSAGE_TYPE_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    CLIENT_CONNECT_MESSAGE_TYPE_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    CLIENT_CONNECT_MESSAGE_TYPE_g_tc._data._annotations._defaultValue._u.long_value = 0;

    CLIENT_CONNECT_MESSAGE_TYPE_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &CLIENT_CONNECT_MESSAGE_TYPE_g_tc;
}
#endif
/* ========================================================================= */
BAC_CONNECT_MESSAGE::BAC_CONNECT_MESSAGE() {
    type = CLIENT_CONNECT_MESSAGE_TYPE::SERVER_CONNECT_SUCCESS;
    msg = "";
}

void BAC_CONNECT_MESSAGE::clear(){
    type = CLIENT_CONNECT_MESSAGE_TYPE::SERVER_CONNECT_SUCCESS;
    msg = "";
}

System::Boolean BAC_CONNECT_MESSAGE::copy_from(BAC_CONNECT_MESSAGE^ src) {

    BAC_CONNECT_MESSAGE^ dst = this;

    dst->type = src->type;
    dst->msg = src->msg;
    return true;
}

Boolean BAC_CONNECT_MESSAGE::Equals(Object^ other) {
    if (other == nullptr) {
        return false;
    }        
    if (this == other) {
        return true;
    }
    BAC_CONNECT_MESSAGE^ otherObj =
    dynamic_cast<BAC_CONNECT_MESSAGE^>(other);
    if (otherObj == nullptr) {
        return false;
    }

    if (type != otherObj->type) {
        return false;
    }
    if (!msg->Equals(otherObj->msg)) {
        return false;
    }
    return true;
}

#ifndef NDDS_STANDALONE_TYPE
DDS::TypeCode^ BAC_CONNECT_MESSAGE::get_typecode() {
    if (_typecode == nullptr) {
        _typecode = gcnew DDS::TypeCode(BAC_CONNECT_MESSAGE_get_typecode());
    }
    return _typecode;
}
#endif

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* BAC_CONNECT_MESSAGE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode BAC_CONNECT_MESSAGE_g_tc_msg_string = DDS_INITIALIZE_STRING_TYPECODE(((MSG_STRING_LEN::VALUE)));

    static DDS_TypeCode_Member BAC_CONNECT_MESSAGE_g_tc_members[2]=
    {

        {
            (char *)"type",/* Member name */
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
        }, 
        {
            (char *)"msg",/* Member name */
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

    static DDS_TypeCode BAC_CONNECT_MESSAGE_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"BAC_CONNECT_MESSAGE", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            BAC_CONNECT_MESSAGE_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for BAC_CONNECT_MESSAGE*/

    if (is_initialized) {
        return &BAC_CONNECT_MESSAGE_g_tc;
    }

    BAC_CONNECT_MESSAGE_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    BAC_CONNECT_MESSAGE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)CLIENT_CONNECT_MESSAGE_TYPE_get_typecode();
    BAC_CONNECT_MESSAGE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&BAC_CONNECT_MESSAGE_g_tc_msg_string;

    /* Initialize the values for member annotations. */
    BAC_CONNECT_MESSAGE_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    BAC_CONNECT_MESSAGE_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

    BAC_CONNECT_MESSAGE_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    BAC_CONNECT_MESSAGE_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    BAC_CONNECT_MESSAGE_g_tc._data._sampleAccessInfo = NULL;

    is_initialized = RTI_TRUE;

    return &BAC_CONNECT_MESSAGE_g_tc;
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

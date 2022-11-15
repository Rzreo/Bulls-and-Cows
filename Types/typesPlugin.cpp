/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from types.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "typesPlugin.h"

#pragma unmanaged
#include "ndds/ndds_cpp.h"
#include "osapi/osapi_utility.h"
#pragma managed

using namespace System::Runtime::InteropServices;

/* ------------------------------------------------------------------------
*  Type Message
* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------
Support functions:
* ------------------------------------------------------------------------ */

void 
MessagePlugin::print_data(
    Message^ sample,
    String^ desc,
    UInt32 indent_level) {

    for (UInt32 i = 0; i < indent_level; ++i) { Console::Write("   "); }

    if (desc != nullptr) {
        Console::WriteLine("{0}:", desc);
    } else {
        Console::WriteLine();
    }

    if (sample == nullptr) {
        Console::WriteLine("null");
        return;
    }

    DataPrintUtility::print_object(
        sample->msg, "msg", indent_level);

}

/* ------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------ */

Boolean 
MessagePlugin::serialize(
    TypePluginDefaultEndpointData^ endpoint_data,
    Message^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char* dheaderPosition = NULL;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (serialize_encapsulation) {
        /* Encapsulate sample */

        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (serialize_sample) {
        Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        if (!inBaseClass_tmp && !xcdr1) {
            dheaderPosition=stream.writeDHeader();
        }

        if (!stream.serialize_string(sample->msg  , (256))) {
            return false;
        }

        if(!xcdr1){            
            if (dheaderPosition!=NULL) {
                stream.setDHeader(dheaderPosition);
            }
        }
    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean 
MessagePlugin::deserialize_sample(
    TypePluginDefaultEndpointData^ endpoint_data,
    Message^ sample,
    CdrStream% stream,   
    Boolean deserialize_encapsulation,
    Boolean deserialize_data, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_data) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        sample->clear();                
        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }
        try{         

            sample->msg = stream.deserialize_string( (256));
            if (sample->msg  == nullptr) {
                return false;
            }
        } catch (System::ApplicationException^  e) {
            if (stream.get_remainder() >= RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
                throw gcnew System::ApplicationException("Error deserializing sample! Remainder: " + stream.get_remainder() + "\n" +
                "Exception caused by: " + e->Message);
            }
        }
        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }
    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean
MessagePlugin::skip(
    TypePluginDefaultEndpointData^ endpoint_data,
    CdrStream% stream,   
    Boolean skip_encapsulation,
    Boolean skip_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (skip_encapsulation) {
        if (!stream.skip_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (skip_sample) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        char * DHtmpPosition = 0;
        UInt32 DHtmpLength = 0;        
        if (!xcdr1 && !inBaseClass_tmp) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            stream.set_current_position((char *)(DHtmpPosition + DHtmpLength));
            if(skip_encapsulation) {
                stream.restore_alignment(rti_position);
            }

            return true;
        }                
        if (!stream.skip_string((256))) {
            return false;
        }
    }

    if(skip_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

/*
size is the offset from the point where we have do a logical reset
Return difference in size, not the final offset.
*/
UInt32 
MessagePlugin::get_serialized_sample_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{

    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment , (256)+1);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return  current_alignment - initial_alignment;
}

UInt32
MessagePlugin::get_serialized_sample_min_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            encapsulation_size);
        current_alignment = 0;
        initial_alignment = 0;

    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment, 1);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return  current_alignment - initial_alignment;
}

UInt32 
MessagePlugin::get_serialized_sample_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment,
    Message^ sample)
{

    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        endpoint_data->set_base_alignment(current_alignment);
    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment += _cdrPrimitiveType->get_string_max_size_serialized(
        endpoint_data->get_alignment(current_alignment), sample->msg);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
MessagePlugin::get_serialized_key_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 encapsulation_size = current_alignment;

    UInt32 initial_alignment = current_alignment;

    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=get_serialized_sample_max_size(
        endpoint_data,false, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;

}

UInt32
MessagePlugin::get_serialized_key_for_keyhash_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{

    UInt32 encapsulation_size = current_alignment;

    UInt32 initial_alignment = current_alignment;

    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);
    if(xcdr1){
        return get_serialized_key_max_size(
            endpoint_data,
            include_encapsulation,
            final_encapsulation_id,
            current_alignment);
    }

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment , (256)+1);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;

}

/* ------------------------------------------------------------------------
Key Management functions:
* ------------------------------------------------------------------------ */

Boolean 
MessagePlugin::serialize_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    Message^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;
    char* dheaderPosition = NULL;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (serialize_encapsulation) {
        /* Encapsulate sample */
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }
        rti_position = stream.reset_alignment();
    }

    if (serialize_key) {
        Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        if (!serialize(
            endpoint_data,
            sample,
            stream,
            false,
            final_encapsulation_id, 
            serialize_key,
            endpoint_plugin_qos)) {
            return false;
        }

    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }
    return true;

}

Boolean 
MessagePlugin::serialize_key_for_keyhash(
    TypePluginDefaultEndpointData^ endpoint_data,
    Message^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;
    Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
    if (xcdr1){
        return this->serialize_key(
            endpoint_data,
            sample,
            stream,
            serialize_encapsulation,
            final_encapsulation_id,
            serialize_key,
            endpoint_plugin_qos);
    }

    if (serialize_encapsulation) {
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }
        rti_position = stream.reset_alignment();
    } else {
        stream.set_cdr_encapsulation(final_encapsulation_id);
    }

    if (serialize_key) {

        if (!stream.serialize_string(sample->msg  , (256))) {
            return false;
        }

    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }
    return true;

}

Boolean MessagePlugin::deserialize_key_sample(
    TypePluginDefaultEndpointData^ endpoint_data,
    Message^ sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,
    Boolean deserialize_key,
    Object^ endpoint_plugin_qos)
{

    CdrStreamPosition rti_position;
    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;  
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_key) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        if (!deserialize_sample(
            endpoint_data, sample, stream,
            false,
            deserialize_key,
            endpoint_plugin_qos)) {
            return false;
        }

    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;

}

Boolean
MessagePlugin::serialized_sample_to_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    Message^ sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_key, 
    Object^ endpoint_plugin_qos)
{

    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_key) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        if (!deserialize_sample(
            endpoint_data,
            sample,
            stream,
            false,
            deserialize_key,
            endpoint_plugin_qos)) {
            return false;
        }

    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;

}

/* ------------------------------------------------------------------------
* Plug-in Lifecycle Methods
* ------------------------------------------------------------------------ */

MessagePlugin^
MessagePlugin::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew MessagePlugin();
    }
    return _singleton;
}

void
MessagePlugin::dispose() {
    delete _singleton;
    _singleton = nullptr;
}

/* ------------------------------------------------------------------------
*  Type Temperature
* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------
Support functions:
* ------------------------------------------------------------------------ */

void 
TemperaturePlugin::print_data(
    Temperature^ sample,
    String^ desc,
    UInt32 indent_level) {

    for (UInt32 i = 0; i < indent_level; ++i) { Console::Write("   "); }

    if (desc != nullptr) {
        Console::WriteLine("{0}:", desc);
    } else {
        Console::WriteLine();
    }

    if (sample == nullptr) {
        Console::WriteLine("null");
        return;
    }

    DataPrintUtility::print_object(
        sample->sensor_id, "sensor_id", indent_level);

    DataPrintUtility::print_object(
        sample->degrees, "degrees", indent_level);

}

/* ------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------ */

Boolean 
TemperaturePlugin::serialize(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char* dheaderPosition = NULL;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (serialize_encapsulation) {
        /* Encapsulate sample */

        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (serialize_sample) {
        Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        if (!inBaseClass_tmp && !xcdr1) {
            dheaderPosition=stream.writeDHeader();
        }

        if (!stream.serialize_string(sample->sensor_id  , ((MAX_STRING_LEN::VALUE)))) {
            return false;
        }
        if (!stream.serialize_long(sample->degrees )) {
            return false;
        }

        if(!xcdr1){            
            if (dheaderPosition!=NULL) {
                stream.setDHeader(dheaderPosition);
            }
        }
    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean 
TemperaturePlugin::deserialize_sample(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ sample,
    CdrStream% stream,   
    Boolean deserialize_encapsulation,
    Boolean deserialize_data, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_data) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        sample->clear();                
        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }
        try{         

            sample->sensor_id = stream.deserialize_string( ((MAX_STRING_LEN::VALUE)));
            if (sample->sensor_id  == nullptr) {
                return false;
            }
            sample->degrees = stream.deserialize_long();
        } catch (System::ApplicationException^  e) {
            if (stream.get_remainder() >= RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
                throw gcnew System::ApplicationException("Error deserializing sample! Remainder: " + stream.get_remainder() + "\n" +
                "Exception caused by: " + e->Message);
            }
        }
        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }
    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean
TemperaturePlugin::skip(
    TypePluginDefaultEndpointData^ endpoint_data,
    CdrStream% stream,   
    Boolean skip_encapsulation,
    Boolean skip_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (skip_encapsulation) {
        if (!stream.skip_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (skip_sample) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        char * DHtmpPosition = 0;
        UInt32 DHtmpLength = 0;        
        if (!xcdr1 && !inBaseClass_tmp) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            stream.set_current_position((char *)(DHtmpPosition + DHtmpLength));
            if(skip_encapsulation) {
                stream.restore_alignment(rti_position);
            }

            return true;
        }                
        if (!stream.skip_string(((MAX_STRING_LEN::VALUE)))) {
            return false;
        }
        if (!stream.skip_long()) {
            return false;
        }
    }

    if(skip_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

/*
size is the offset from the point where we have do a logical reset
Return difference in size, not the final offset.
*/
UInt32 
TemperaturePlugin::get_serialized_sample_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{

    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment , ((MAX_STRING_LEN::VALUE))+1);

    current_alignment +=_cdrPrimitiveType->get_long_max_size_serialized(
        current_alignment );

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return  current_alignment - initial_alignment;
}

UInt32
TemperaturePlugin::get_serialized_sample_min_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            encapsulation_size);
        current_alignment = 0;
        initial_alignment = 0;

    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment, 1);
    current_alignment +=_cdrPrimitiveType->get_long_max_size_serialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return  current_alignment - initial_alignment;
}

UInt32 
TemperaturePlugin::get_serialized_sample_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment,
    Temperature^ sample)
{

    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        endpoint_data->set_base_alignment(current_alignment);
    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment += _cdrPrimitiveType->get_string_max_size_serialized(
        endpoint_data->get_alignment(current_alignment), sample->sensor_id);

    current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(
        endpoint_data->get_alignment(current_alignment));
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
TemperaturePlugin::get_serialized_key_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 encapsulation_size = current_alignment;

    UInt32 initial_alignment = current_alignment;

    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment , ((MAX_STRING_LEN::VALUE))+1);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;

}

UInt32
TemperaturePlugin::get_serialized_key_for_keyhash_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{

    UInt32 encapsulation_size = current_alignment;

    UInt32 initial_alignment = current_alignment;

    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);
    if(xcdr1){
        return get_serialized_key_max_size(
            endpoint_data,
            include_encapsulation,
            final_encapsulation_id,
            current_alignment);
    }

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment +=_cdrPrimitiveType->get_string_max_size_serialized(
        current_alignment , ((MAX_STRING_LEN::VALUE))+1);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;

}

/* ------------------------------------------------------------------------
Key Management functions:
* ------------------------------------------------------------------------ */

Boolean 
TemperaturePlugin::serialize_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;
    char* dheaderPosition = NULL;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (serialize_encapsulation) {
        /* Encapsulate sample */
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }
        rti_position = stream.reset_alignment();
    }

    if (serialize_key) {
        Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        if (!inBaseClass_tmp && !xcdr1) {
            dheaderPosition=stream.writeDHeader();
        }
        if (!stream.serialize_string(sample->sensor_id  , ((MAX_STRING_LEN::VALUE)))) {
            return false;
        }

        if(!xcdr1){            
            if (dheaderPosition!=NULL) {
                stream.setDHeader(dheaderPosition);
            }
        }          

    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }
    return true;

}

Boolean 
TemperaturePlugin::serialize_key_for_keyhash(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;
    Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
    if (xcdr1){
        return this->serialize_key(
            endpoint_data,
            sample,
            stream,
            serialize_encapsulation,
            final_encapsulation_id,
            serialize_key,
            endpoint_plugin_qos);
    }

    if (serialize_encapsulation) {
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }
        rti_position = stream.reset_alignment();
    } else {
        stream.set_cdr_encapsulation(final_encapsulation_id);
    }

    if (serialize_key) {

        if (!stream.serialize_string(sample->sensor_id  , ((MAX_STRING_LEN::VALUE)))) {
            return false;
        }

    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }
    return true;

}

Boolean TemperaturePlugin::deserialize_key_sample(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,
    Boolean deserialize_key,
    Object^ endpoint_plugin_qos)
{

    CdrStreamPosition rti_position;
    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;  
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_key) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }

        sample->sensor_id = stream.deserialize_string( ((MAX_STRING_LEN::VALUE)));
        if (sample->sensor_id  == nullptr) {
            return false;
        }

        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }

    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;

}

Boolean
TemperaturePlugin::serialized_sample_to_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_key, 
    Object^ endpoint_plugin_qos)
{

    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_key) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }
        sample->sensor_id = stream.deserialize_string( ((MAX_STRING_LEN::VALUE)));
        if (sample->sensor_id  == nullptr) {
            return false;
        }
        if (!stream.skip_long()) {
            return false;
        }

        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }

    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;

}
Boolean 
TemperaturePlugin::instance_to_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ dst, 
    Temperature^ src)
{

    dst->sensor_id = src->sensor_id;

    return true;
}

Boolean 
TemperaturePlugin::key_to_instance(
    TypePluginDefaultEndpointData^ endpoint_data,
    Temperature^ dst,
    Temperature^ src)
{

    dst->sensor_id = src->sensor_id;
    return true;
}

Boolean 
TemperaturePlugin::serialized_sample_to_key_hash(
    TypePluginDefaultEndpointData^ endpoint_data,
    CdrStream% stream, 
    KeyHash_t% key_hash,
    Boolean deserialize_encapsulation,
    Object^ endpoint_plugin_qos) 
{   
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();
    }

    UInt16 encapsulation_id = stream.get_encapsulation_kind();
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

    GCHandle sample_handle = GCHandle::FromIntPtr(IntPtr(const_cast<void*>(endpoint_data->get_temp_sample())));
    Temperature^ sample = static_cast<Temperature^>(sample_handle.Target);
    if (sample == nullptr) {
        return false;
    }

    char * DHtmpPosition = 0;
    UInt32 DHtmpSize = 0;
    UInt32 DHtmpLength = 0;
    if (!inBaseClass_tmp && !xcdr1) {
        DHtmpLength = stream.deserialize_unsigned_long();
        DHtmpPosition = stream.get_current_position().toChar();
        DHtmpSize = stream.get_buffer_length(); 
        stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
    }
    try{        

        sample->sensor_id = stream.deserialize_string( ((MAX_STRING_LEN::VALUE)));
        if (sample->sensor_id  == nullptr) {
            return false;
        }

    } catch (System::ApplicationException^  e) {
        if (stream.get_remainder() >= RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            throw gcnew System::ApplicationException("Error deserializing sample! Remainder: " + stream.get_remainder() + "\n" +
            "Exception caused by: " + e->Message);
        }
    }
    if (!inBaseClass_tmp && !xcdr1) {
        stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
    }
    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    if (!instance_to_key_hash(
        endpoint_data,
        key_hash,
        sample,
        stream.get_encapsulation_kind())) {
        return false;
    }

    return true;
}

/* ------------------------------------------------------------------------
* Plug-in Lifecycle Methods
* ------------------------------------------------------------------------ */

TemperaturePlugin^
TemperaturePlugin::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew TemperaturePlugin();
    }
    return _singleton;
}

void
TemperaturePlugin::dispose() {
    delete _singleton;
    _singleton = nullptr;
}

/* ------------------------------------------------------------------------
Enum Type: StationKind
* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------
* (De)Serialization Methods
* ------------------------------------------------------------------------ */

Boolean
StationKindPlugin::serialize(
    TypePluginEndpointData^ endpoint_data,
    StationKind sample,
    CdrStream% stream, 
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_sample,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    if (serialize_encapsulation) {
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (serialize_sample) {

        if (!stream.serialize_enum(sample)) {
            return false;
        }

    }

    if (serialize_encapsulation) {
        stream.restore_alignment(rti_position);

    }

    return true;
}

Boolean 
StationKindPlugin::deserialize_sample(
    TypePluginEndpointData^ endpoint_data,
    StationKind% sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_data, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    if (deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_data) {

        sample = stream.deserialize_enum<StationKind>();

        switch (sample){
            case StationKind::INVALID_CONTROLLER:
            case StationKind::COCOA_BUTTER_CONTROLLER:
            case StationKind::SUGAR_CONTROLLER:
            case StationKind::MILK_CONTROLLER:
            case StationKind::VANILLA_CONTROLLER:
            case StationKind::TEMPERING_CONTROLLER:
            {
            }  break;
            default:
            {
                TypePluginDefaultEndpointData^ epd = 
                (TypePluginDefaultEndpointData^)endpoint_data;

                if (epd == nullptr || epd->sample_assignability_property.acceptUnknownEnumValue) {
                    sample = StationKind::INVALID_CONTROLLER;
                } else {
                    throw gcnew Unassignable("invalid enumerator " + sample.ToString());
                }
            } break;
        }

    }
    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean
StationKindPlugin::skip(
    TypePluginEndpointData^ endpoint_data,
    CdrStream% stream, 
    Boolean skip_encapsulation,  
    Boolean skip_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    if (skip_encapsulation) {
        if (!stream.skip_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }
    if (skip_sample) {

        if (!stream.skip_enum()) {
            return false;
        }

    }

    if(skip_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

UInt32
StationKindPlugin::get_serialized_sample_max_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
StationKindPlugin::get_serialized_sample_min_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
StationKindPlugin::get_serialized_sample_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment,
    StationKind sample) 
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;

    TypePluginDefaultEndpointData^ epd = static_cast<TypePluginDefaultEndpointData^>(endpoint_data);
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;
        epd->set_base_alignment(current_alignment);   
    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(
        epd->get_alignment(current_alignment));

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* ------------------------------------------------------------------------
Key Management functions:
* ------------------------------------------------------------------------ */

Boolean
StationKindPlugin::serialize_key(
    TypePluginEndpointData^ endpoint_data,
    StationKind sample,
    CdrStream% stream,
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    return serialize(
        endpoint_data, sample, stream, serialize_encapsulation, 
        final_encapsulation_id, 
        serialize_key, endpoint_plugin_qos);
}

Boolean
StationKindPlugin::serialize_key_for_keyhash(
    TypePluginEndpointData^ endpoint_data,
    StationKind sample,
    CdrStream% stream,
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    return serialize(
        endpoint_data, sample, stream, serialize_encapsulation, 
        final_encapsulation_id, 
        serialize_key, endpoint_plugin_qos);
}

Boolean
StationKindPlugin::deserialize_key_sample(
    TypePluginEndpointData^ endpoint_data,
    StationKind% sample,
    CdrStream% stream,
    Boolean deserialize_encapsulation,
    Boolean deserialize_key,
    Object^ endpoint_plugin_qos)
{
    return deserialize_sample(
        endpoint_data, sample, stream, deserialize_encapsulation, 
        deserialize_key, endpoint_plugin_qos);
}

UInt32
StationKindPlugin::get_serialized_key_max_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    current_alignment += get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id,current_alignment);

    return current_alignment - initial_alignment;
}

UInt32
StationKindPlugin::get_serialized_key_for_keyhash_max_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    current_alignment += get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id,current_alignment);

    return current_alignment - initial_alignment;
}

Boolean
StationKindPlugin::serialized_sample_to_key(
    TypePluginEndpointData^ endpoint_data,
    StationKind% sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_key, 
    Object^ endpoint_plugin_qos)
{    
    return deserialize_sample(
        endpoint_data,
        sample,
        stream,
        deserialize_encapsulation, 
        deserialize_key,
        endpoint_plugin_qos);
}

/* ------------------------------------------------------------------------
Support functions:
* ------------------------------------------------------------------------ */

void
StationKindPlugin::print_data(
    StationKind sample,
    String^ description,
    UInt32 indent_level)
{
    if (description != nullptr) {
        for (UInt32 i = 0; i < indent_level; ++i) { Console::Write("   "); }
        Console::WriteLine("{0}:", description);
    }

    RTICdrType_printEnum((RTICdrEnum*) &sample,
    "StationKind", indent_level + 1);
}
/* ------------------------------------------------------------------------
* Plug-in Lifecycle Methods
* ------------------------------------------------------------------------ */

StationKindPlugin^
StationKindPlugin::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew StationKindPlugin();
    }
    return _singleton;
}

void
StationKindPlugin::dispose() {
    delete _singleton;
    _singleton = nullptr;
}

/* ------------------------------------------------------------------------
Enum Type: LotStatusKind
* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------
* (De)Serialization Methods
* ------------------------------------------------------------------------ */

Boolean
LotStatusKindPlugin::serialize(
    TypePluginEndpointData^ endpoint_data,
    LotStatusKind sample,
    CdrStream% stream, 
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_sample,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    if (serialize_encapsulation) {
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (serialize_sample) {

        if (!stream.serialize_enum(sample)) {
            return false;
        }

    }

    if (serialize_encapsulation) {
        stream.restore_alignment(rti_position);

    }

    return true;
}

Boolean 
LotStatusKindPlugin::deserialize_sample(
    TypePluginEndpointData^ endpoint_data,
    LotStatusKind% sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_data, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    if (deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_data) {

        sample = stream.deserialize_enum<LotStatusKind>();

        switch (sample){
            case LotStatusKind::WAITING:
            case LotStatusKind::PROCESSING:
            case LotStatusKind::COMPLETED:
            {
            }  break;
            default:
            {
                TypePluginDefaultEndpointData^ epd = 
                (TypePluginDefaultEndpointData^)endpoint_data;

                if (epd == nullptr || epd->sample_assignability_property.acceptUnknownEnumValue) {
                    sample = LotStatusKind::WAITING;
                } else {
                    throw gcnew Unassignable("invalid enumerator " + sample.ToString());
                }
            } break;
        }

    }
    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean
LotStatusKindPlugin::skip(
    TypePluginEndpointData^ endpoint_data,
    CdrStream% stream, 
    Boolean skip_encapsulation,  
    Boolean skip_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    if (skip_encapsulation) {
        if (!stream.skip_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }
    if (skip_sample) {

        if (!stream.skip_enum()) {
            return false;
        }

    }

    if(skip_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

UInt32
LotStatusKindPlugin::get_serialized_sample_max_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
LotStatusKindPlugin::get_serialized_sample_min_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
LotStatusKindPlugin::get_serialized_sample_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment,
    LotStatusKind sample) 
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;

    TypePluginDefaultEndpointData^ epd = static_cast<TypePluginDefaultEndpointData^>(endpoint_data);
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;
        epd->set_base_alignment(current_alignment);   
    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(
        epd->get_alignment(current_alignment));

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* ------------------------------------------------------------------------
Key Management functions:
* ------------------------------------------------------------------------ */

Boolean
LotStatusKindPlugin::serialize_key(
    TypePluginEndpointData^ endpoint_data,
    LotStatusKind sample,
    CdrStream% stream,
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    return serialize(
        endpoint_data, sample, stream, serialize_encapsulation, 
        final_encapsulation_id, 
        serialize_key, endpoint_plugin_qos);
}

Boolean
LotStatusKindPlugin::serialize_key_for_keyhash(
    TypePluginEndpointData^ endpoint_data,
    LotStatusKind sample,
    CdrStream% stream,
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    return serialize(
        endpoint_data, sample, stream, serialize_encapsulation, 
        final_encapsulation_id, 
        serialize_key, endpoint_plugin_qos);
}

Boolean
LotStatusKindPlugin::deserialize_key_sample(
    TypePluginEndpointData^ endpoint_data,
    LotStatusKind% sample,
    CdrStream% stream,
    Boolean deserialize_encapsulation,
    Boolean deserialize_key,
    Object^ endpoint_plugin_qos)
{
    return deserialize_sample(
        endpoint_data, sample, stream, deserialize_encapsulation, 
        deserialize_key, endpoint_plugin_qos);
}

UInt32
LotStatusKindPlugin::get_serialized_key_max_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    current_alignment += get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id,current_alignment);

    return current_alignment - initial_alignment;
}

UInt32
LotStatusKindPlugin::get_serialized_key_for_keyhash_max_size(
    TypePluginEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    current_alignment += get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id,current_alignment);

    return current_alignment - initial_alignment;
}

Boolean
LotStatusKindPlugin::serialized_sample_to_key(
    TypePluginEndpointData^ endpoint_data,
    LotStatusKind% sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_key, 
    Object^ endpoint_plugin_qos)
{    
    return deserialize_sample(
        endpoint_data,
        sample,
        stream,
        deserialize_encapsulation, 
        deserialize_key,
        endpoint_plugin_qos);
}

/* ------------------------------------------------------------------------
Support functions:
* ------------------------------------------------------------------------ */

void
LotStatusKindPlugin::print_data(
    LotStatusKind sample,
    String^ description,
    UInt32 indent_level)
{
    if (description != nullptr) {
        for (UInt32 i = 0; i < indent_level; ++i) { Console::Write("   "); }
        Console::WriteLine("{0}:", description);
    }

    RTICdrType_printEnum((RTICdrEnum*) &sample,
    "LotStatusKind", indent_level + 1);
}
/* ------------------------------------------------------------------------
* Plug-in Lifecycle Methods
* ------------------------------------------------------------------------ */

LotStatusKindPlugin^
LotStatusKindPlugin::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew LotStatusKindPlugin();
    }
    return _singleton;
}

void
LotStatusKindPlugin::dispose() {
    delete _singleton;
    _singleton = nullptr;
}

/* ------------------------------------------------------------------------
*  Type ChocolateLotState
* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------
Support functions:
* ------------------------------------------------------------------------ */

void 
ChocolateLotStatePlugin::print_data(
    ChocolateLotState^ sample,
    String^ desc,
    UInt32 indent_level) {

    for (UInt32 i = 0; i < indent_level; ++i) { Console::Write("   "); }

    if (desc != nullptr) {
        Console::WriteLine("{0}:", desc);
    } else {
        Console::WriteLine();
    }

    if (sample == nullptr) {
        Console::WriteLine("null");
        return;
    }

    DataPrintUtility::print_object(
        sample->lot_id, "lot_id", indent_level);

    DataPrintUtility::print_object(
        sample->station, "station", indent_level);

    DataPrintUtility::print_object(
        sample->next_station, "next_station", indent_level);

    DataPrintUtility::print_object(
        sample->lot_status, "lot_status", indent_level);

}

/* ------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------ */

Boolean 
ChocolateLotStatePlugin::serialize(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char* dheaderPosition = NULL;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (serialize_encapsulation) {
        /* Encapsulate sample */

        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (serialize_sample) {
        Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        if (!inBaseClass_tmp && !xcdr1) {
            dheaderPosition=stream.writeDHeader();
        }

        if (!stream.serialize_unsigned_long(sample->lot_id )) {
            return false;
        }
        if (!StationKindPlugin::get_instance()->serialize(
            endpoint_data,
            sample->station,
            stream,
            false, // serialize encapsulation header
            final_encapsulation_id,
            true,  // serialize data
            endpoint_plugin_qos)) {
            return false;
        }
        if (!StationKindPlugin::get_instance()->serialize(
            endpoint_data,
            sample->next_station,
            stream,
            false, // serialize encapsulation header
            final_encapsulation_id,
            true,  // serialize data
            endpoint_plugin_qos)) {
            return false;
        }
        if (!LotStatusKindPlugin::get_instance()->serialize(
            endpoint_data,
            sample->lot_status,
            stream,
            false, // serialize encapsulation header
            final_encapsulation_id,
            true,  // serialize data
            endpoint_plugin_qos)) {
            return false;
        }

        if(!xcdr1){            
            if (dheaderPosition!=NULL) {
                stream.setDHeader(dheaderPosition);
            }
        }
    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean 
ChocolateLotStatePlugin::deserialize_sample(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ sample,
    CdrStream% stream,   
    Boolean deserialize_encapsulation,
    Boolean deserialize_data, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_data) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        sample->clear();                
        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }
        try{         

            sample->lot_id = stream.deserialize_unsigned_long();
            if (!StationKindPlugin::get_instance()->deserialize_sample(
                endpoint_data,
                sample->station,
                stream,
                false, // deserialize encapsulation header
                true,  // deserialize data
                endpoint_plugin_qos)) {
                return false;
            }
            if (!StationKindPlugin::get_instance()->deserialize_sample(
                endpoint_data,
                sample->next_station,
                stream,
                false, // deserialize encapsulation header
                true,  // deserialize data
                endpoint_plugin_qos)) {
                return false;
            }
            if (!LotStatusKindPlugin::get_instance()->deserialize_sample(
                endpoint_data,
                sample->lot_status,
                stream,
                false, // deserialize encapsulation header
                true,  // deserialize data
                endpoint_plugin_qos)) {
                return false;
            }
        } catch (System::ApplicationException^  e) {
            if (stream.get_remainder() >= RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
                throw gcnew System::ApplicationException("Error deserializing sample! Remainder: " + stream.get_remainder() + "\n" +
                "Exception caused by: " + e->Message);
            }
        }
        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }
    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

Boolean
ChocolateLotStatePlugin::skip(
    TypePluginDefaultEndpointData^ endpoint_data,
    CdrStream% stream,   
    Boolean skip_encapsulation,
    Boolean skip_sample, 
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (skip_encapsulation) {
        if (!stream.skip_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (skip_sample) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        char * DHtmpPosition = 0;
        UInt32 DHtmpLength = 0;        
        if (!xcdr1 && !inBaseClass_tmp) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            stream.set_current_position((char *)(DHtmpPosition + DHtmpLength));
            if(skip_encapsulation) {
                stream.restore_alignment(rti_position);
            }

            return true;
        }                
        if (!stream.skip_unsigned_long()) {
            return false;
        }
        if (!StationKindPlugin::get_instance()->skip(
            endpoint_data,
            stream, 
            false, true, 
            endpoint_plugin_qos)) {
            return false;
        }
        if (!StationKindPlugin::get_instance()->skip(
            endpoint_data,
            stream, 
            false, true, 
            endpoint_plugin_qos)) {
            return false;
        }
        if (!LotStatusKindPlugin::get_instance()->skip(
            endpoint_data,
            stream, 
            false, true, 
            endpoint_plugin_qos)) {
            return false;
        }
    }

    if(skip_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;
}

/*
size is the offset from the point where we have do a logical reset
Return difference in size, not the final offset.
*/
UInt32 
ChocolateLotStatePlugin::get_serialized_sample_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{

    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_unsigned_long_max_size_serialized(
        current_alignment );

    current_alignment +=  StationKindPlugin::get_instance()->get_serialized_sample_max_size(
        endpoint_data, false, final_encapsulation_id, current_alignment);

    current_alignment +=  StationKindPlugin::get_instance()->get_serialized_sample_max_size(
        endpoint_data, false, final_encapsulation_id, current_alignment);

    current_alignment +=  LotStatusKindPlugin::get_instance()->get_serialized_sample_max_size(
        endpoint_data, false, final_encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return  current_alignment - initial_alignment;
}

UInt32
ChocolateLotStatePlugin::get_serialized_sample_min_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            encapsulation_size);
        current_alignment = 0;
        initial_alignment = 0;

    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_unsigned_long_max_size_serialized(
        current_alignment);
    current_alignment +=  StationKindPlugin::get_instance()->get_serialized_sample_min_size(
        endpoint_data, false, final_encapsulation_id, current_alignment);

    current_alignment +=  StationKindPlugin::get_instance()->get_serialized_sample_min_size(
        endpoint_data, false, final_encapsulation_id, current_alignment);

    current_alignment +=  LotStatusKindPlugin::get_instance()->get_serialized_sample_min_size(
        endpoint_data, false, final_encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return  current_alignment - initial_alignment;
}

UInt32 
ChocolateLotStatePlugin::get_serialized_sample_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment,
    ChocolateLotState^ sample)
{

    UInt32 initial_alignment = current_alignment;

    UInt32 encapsulation_size = current_alignment;
    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        endpoint_data->set_base_alignment(current_alignment);
    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment += _cdrPrimitiveType->get_unsigned_long_max_size_serialized(
        endpoint_data->get_alignment(current_alignment));

    current_alignment += StationKindPlugin::get_instance()->get_serialized_sample_size(
        endpoint_data, false, final_encapsulation_id, current_alignment, sample->station);

    current_alignment += StationKindPlugin::get_instance()->get_serialized_sample_size(
        endpoint_data, false, final_encapsulation_id, current_alignment, sample->next_station);

    current_alignment += LotStatusKindPlugin::get_instance()->get_serialized_sample_size(
        endpoint_data, false, final_encapsulation_id, current_alignment, sample->lot_status);
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

UInt32
ChocolateLotStatePlugin::get_serialized_key_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{
    UInt32 encapsulation_size = current_alignment;

    UInt32 initial_alignment = current_alignment;

    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    if (!xcdr1) {
        //DHeader
        current_alignment += _cdrPrimitiveType->get_long_max_size_serialized(current_alignment);
    }

    current_alignment +=_cdrPrimitiveType->get_unsigned_long_max_size_serialized(
        current_alignment );

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;

}

UInt32
ChocolateLotStatePlugin::get_serialized_key_for_keyhash_max_size(
    TypePluginDefaultEndpointData^ endpoint_data,
    Boolean include_encapsulation,
    UInt16 final_encapsulation_id,
    UInt32 current_alignment)
{

    UInt32 encapsulation_size = current_alignment;

    UInt32 initial_alignment = current_alignment;

    CdrPrimitiveType ^ _cdrPrimitiveType = CdrPrimitiveType::get_cdr_primitive_type_instance(final_encapsulation_id);
    UInt16 encapsulation_id = CdrEncapsulation::get_encapsulation_from_final(
        final_encapsulation_id,
        ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY);
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE);
    if(xcdr1){
        return get_serialized_key_max_size(
            endpoint_data,
            include_encapsulation,
            final_encapsulation_id,
            current_alignment);
    }

    if (include_encapsulation) {
        if (!CdrStream::valid_encapsulation_id(encapsulation_id)) {
            return 1;
        }

        encapsulation_size = CdrPrimitiveType::get_encapsulation_serialized_size(
            current_alignment);
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment +=_cdrPrimitiveType->get_unsigned_long_max_size_serialized(
        current_alignment );

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;

}

/* ------------------------------------------------------------------------
Key Management functions:
* ------------------------------------------------------------------------ */

Boolean 
ChocolateLotStatePlugin::serialize_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;
    char* dheaderPosition = NULL;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (serialize_encapsulation) {
        /* Encapsulate sample */
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }
        rti_position = stream.reset_alignment();
    }

    if (serialize_key) {
        Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
        if (!inBaseClass_tmp && !xcdr1) {
            dheaderPosition=stream.writeDHeader();
        }
        if (!stream.serialize_unsigned_long(sample->lot_id )) {
            return false;
        }

        if(!xcdr1){            
            if (dheaderPosition!=NULL) {
                stream.setDHeader(dheaderPosition);
            }
        }          

    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }
    return true;

}

Boolean 
ChocolateLotStatePlugin::serialize_key_for_keyhash(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ sample,
    CdrStream% stream,    
    Boolean serialize_encapsulation,
    UInt16 final_encapsulation_id,
    Boolean serialize_key,
    Object^ endpoint_plugin_qos)
{
    CdrStreamPosition rti_position;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;
    Boolean xcdr1 = (final_encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;
    if (xcdr1){
        return this->serialize_key(
            endpoint_data,
            sample,
            stream,
            serialize_encapsulation,
            final_encapsulation_id,
            serialize_key,
            endpoint_plugin_qos);
    }

    if (serialize_encapsulation) {
        if (!stream.serialize_and_set_cdr_encapsulation(final_encapsulation_id, ExtensibilityKind::EXTENSIBLE_EXTENSIBILITY)) {
            return false;
        }
        rti_position = stream.reset_alignment();
    } else {
        stream.set_cdr_encapsulation(final_encapsulation_id);
    }

    if (serialize_key) {

        if (!stream.serialize_unsigned_long(sample->lot_id )) {
            return false;
        }

    }

    if(serialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }
    return true;

}

Boolean ChocolateLotStatePlugin::deserialize_key_sample(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,
    Boolean deserialize_key,
    Object^ endpoint_plugin_qos)
{

    CdrStreamPosition rti_position;
    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;
    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if (deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;  
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_key) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }

        sample->lot_id = stream.deserialize_unsigned_long();

        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }

    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;

}

Boolean
ChocolateLotStatePlugin::serialized_sample_to_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ sample,
    CdrStream% stream, 
    Boolean deserialize_encapsulation,  
    Boolean deserialize_key, 
    Object^ endpoint_plugin_qos)
{

    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();

    }

    if (deserialize_key) {
        UInt16 encapsulation_id = stream.get_encapsulation_kind();
        Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

        char * DHtmpPosition = 0;
        UInt32 DHtmpSize = 0;
        UInt32 DHtmpLength = 0;
        if (!inBaseClass_tmp && !xcdr1) {
            DHtmpLength = stream.deserialize_unsigned_long();
            DHtmpPosition = stream.get_current_position().toChar();
            DHtmpSize = stream.get_buffer_length(); 
            stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
        }
        sample->lot_id = stream.deserialize_unsigned_long();
        if (!StationKindPlugin::get_instance()->skip(
            endpoint_data,
            stream, 
            false, true, 
            endpoint_plugin_qos)) {
            return false;
        }

        if (!StationKindPlugin::get_instance()->skip(
            endpoint_data,
            stream, 
            false, true, 
            endpoint_plugin_qos)) {
            return false;
        }

        if (!LotStatusKindPlugin::get_instance()->skip(
            endpoint_data,
            stream, 
            false, true, 
            endpoint_plugin_qos)) {
            return false;
        }

        if (!inBaseClass_tmp && !xcdr1) {
            stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
        }

    }

    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    return true;

}
Boolean 
ChocolateLotStatePlugin::instance_to_key(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ dst, 
    ChocolateLotState^ src)
{

    dst->lot_id = src->lot_id;

    return true;
}

Boolean 
ChocolateLotStatePlugin::key_to_instance(
    TypePluginDefaultEndpointData^ endpoint_data,
    ChocolateLotState^ dst,
    ChocolateLotState^ src)
{

    dst->lot_id = src->lot_id;
    return true;
}

Boolean 
ChocolateLotStatePlugin::serialized_sample_to_key_hash(
    TypePluginDefaultEndpointData^ endpoint_data,
    CdrStream% stream, 
    KeyHash_t% key_hash,
    Boolean deserialize_encapsulation,
    Object^ endpoint_plugin_qos) 
{   
    CdrStreamPosition rti_position;

    char * tmpPosition = 0;
    UInt32 tmpSize = 0;
    UInt32 tmpLength = 0;
    char * buffer = nullptr;

    Boolean inBaseClass_tmp = stream.inBaseClass;
    stream.inBaseClass = false;

    if(deserialize_encapsulation) {
        if (!stream.deserialize_and_set_cdr_encapsulation()) {
            return false;
        }

        rti_position = stream.reset_alignment();
    }

    UInt16 encapsulation_id = stream.get_encapsulation_kind();
    Boolean xcdr1 = (encapsulation_id <= CdrEncapsulation::CDR_ENCAPSULATION_ID_PL_CDR_LE)? true: false;

    GCHandle sample_handle = GCHandle::FromIntPtr(IntPtr(const_cast<void*>(endpoint_data->get_temp_sample())));
    ChocolateLotState^ sample = static_cast<ChocolateLotState^>(sample_handle.Target);
    if (sample == nullptr) {
        return false;
    }

    char * DHtmpPosition = 0;
    UInt32 DHtmpSize = 0;
    UInt32 DHtmpLength = 0;
    if (!inBaseClass_tmp && !xcdr1) {
        DHtmpLength = stream.deserialize_unsigned_long();
        DHtmpPosition = stream.get_current_position().toChar();
        DHtmpSize = stream.get_buffer_length(); 
        stream.set_buffer_length((UInt32)((UInt64)DHtmpPosition - (UInt64)stream.get_buffer_begin()) + DHtmpLength);
    }
    try{        

        sample->lot_id = stream.deserialize_unsigned_long();

    } catch (System::ApplicationException^  e) {
        if (stream.get_remainder() >= RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            throw gcnew System::ApplicationException("Error deserializing sample! Remainder: " + stream.get_remainder() + "\n" +
            "Exception caused by: " + e->Message);
        }
    }
    if (!inBaseClass_tmp && !xcdr1) {
        stream.restore_buffer((char *)(DHtmpPosition + DHtmpLength), DHtmpSize);
    }
    if(deserialize_encapsulation) {
        stream.restore_alignment(rti_position);
    }

    if (!instance_to_key_hash(
        endpoint_data,
        key_hash,
        sample,
        stream.get_encapsulation_kind())) {
        return false;
    }

    return true;
}

/* ------------------------------------------------------------------------
* Plug-in Lifecycle Methods
* ------------------------------------------------------------------------ */

ChocolateLotStatePlugin^
ChocolateLotStatePlugin::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew ChocolateLotStatePlugin();
    }
    return _singleton;
}

void
ChocolateLotStatePlugin::dispose() {
    delete _singleton;
    _singleton = nullptr;
}


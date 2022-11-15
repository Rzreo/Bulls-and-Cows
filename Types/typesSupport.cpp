/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from types.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "typesSupport.h"
#include "typesPlugin.h"

#pragma unmanaged
#include "ndds/ndds_cpp.h"
#pragma managed

using namespace System;
using namespace DDS;

/* ========================================================================= */

// ---------------------------------------------------------------------------
// MessageDataWriter
// ---------------------------------------------------------------------------

MessageDataWriter::MessageDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<Message^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// MessageDataReader
// ---------------------------------------------------------------------------

MessageDataReader::MessageDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<Message^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// MessageTypeSupport
// ---------------------------------------------------------------------------

MessageTypeSupport::MessageTypeSupport()
: DDS::TypedTypeSupport<Message^>(
    MessagePlugin::get_instance()) {

    _type_plugin = MessagePlugin::get_instance();
}

void MessageTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void MessageTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

Message^ MessageTypeSupport::create_data() {
    return gcnew Message();
}

Message^ MessageTypeSupport::create_data_untyped() {
    return create_data();
}

void MessageTypeSupport::delete_data(
    Message^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void MessageTypeSupport::print_data(Message^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void MessageTypeSupport::copy_data(
    Message^ dst, Message^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void MessageTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    Message^ a_data,
    System::Int16 representation)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(
        buffer,
        length,
        a_data,
        representation)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void MessageTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    Message^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void MessageTypeSupport::deserialize_data_from_cdr_buffer(
    Message^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

#ifndef NDDS_STANDALONE_TYPE
System::String^ MessageTypeSupport::data_to_string(
    Message ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ MessageTypeSupport::data_to_string(
    Message ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}
#endif

DDS::TypeCode^ MessageTypeSupport::get_typecode() {
    #ifndef NDDS_STANDALONE_TYPE
    return  Message::get_typecode();
    #else
    return nullptr;
    #endif
}

System::String^ MessageTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ MessageTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ MessageTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew MessageDataReader(impl);
}

DDS::DataWriter^ MessageTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew MessageDataWriter(impl);
}

MessageTypeSupport^
MessageTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew MessageTypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// TemperatureDataWriter
// ---------------------------------------------------------------------------

TemperatureDataWriter::TemperatureDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<Temperature^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// TemperatureDataReader
// ---------------------------------------------------------------------------

TemperatureDataReader::TemperatureDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<Temperature^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// TemperatureTypeSupport
// ---------------------------------------------------------------------------

TemperatureTypeSupport::TemperatureTypeSupport()
: DDS::TypedTypeSupport<Temperature^>(
    TemperaturePlugin::get_instance()) {

    _type_plugin = TemperaturePlugin::get_instance();
}

void TemperatureTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void TemperatureTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

Temperature^ TemperatureTypeSupport::create_data() {
    return gcnew Temperature();
}

Temperature^ TemperatureTypeSupport::create_data_untyped() {
    return create_data();
}

void TemperatureTypeSupport::delete_data(
    Temperature^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void TemperatureTypeSupport::print_data(Temperature^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void TemperatureTypeSupport::copy_data(
    Temperature^ dst, Temperature^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void TemperatureTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    Temperature^ a_data,
    System::Int16 representation)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(
        buffer,
        length,
        a_data,
        representation)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void TemperatureTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    Temperature^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void TemperatureTypeSupport::deserialize_data_from_cdr_buffer(
    Temperature^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

#ifndef NDDS_STANDALONE_TYPE
System::String^ TemperatureTypeSupport::data_to_string(
    Temperature ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ TemperatureTypeSupport::data_to_string(
    Temperature ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}
#endif

DDS::TypeCode^ TemperatureTypeSupport::get_typecode() {
    #ifndef NDDS_STANDALONE_TYPE
    return  Temperature::get_typecode();
    #else
    return nullptr;
    #endif
}

System::String^ TemperatureTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ TemperatureTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ TemperatureTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew TemperatureDataReader(impl);
}

DDS::DataWriter^ TemperatureTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew TemperatureDataWriter(impl);
}

TemperatureTypeSupport^
TemperatureTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew TemperatureTypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// ChocolateLotStateDataWriter
// ---------------------------------------------------------------------------

ChocolateLotStateDataWriter::ChocolateLotStateDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<ChocolateLotState^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// ChocolateLotStateDataReader
// ---------------------------------------------------------------------------

ChocolateLotStateDataReader::ChocolateLotStateDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<ChocolateLotState^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// ChocolateLotStateTypeSupport
// ---------------------------------------------------------------------------

ChocolateLotStateTypeSupport::ChocolateLotStateTypeSupport()
: DDS::TypedTypeSupport<ChocolateLotState^>(
    ChocolateLotStatePlugin::get_instance()) {

    _type_plugin = ChocolateLotStatePlugin::get_instance();
}

void ChocolateLotStateTypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void ChocolateLotStateTypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

ChocolateLotState^ ChocolateLotStateTypeSupport::create_data() {
    return gcnew ChocolateLotState();
}

ChocolateLotState^ ChocolateLotStateTypeSupport::create_data_untyped() {
    return create_data();
}

void ChocolateLotStateTypeSupport::delete_data(
    ChocolateLotState^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void ChocolateLotStateTypeSupport::print_data(ChocolateLotState^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void ChocolateLotStateTypeSupport::copy_data(
    ChocolateLotState^ dst, ChocolateLotState^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void ChocolateLotStateTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    ChocolateLotState^ a_data,
    System::Int16 representation)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(
        buffer,
        length,
        a_data,
        representation)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void ChocolateLotStateTypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    ChocolateLotState^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void ChocolateLotStateTypeSupport::deserialize_data_from_cdr_buffer(
    ChocolateLotState^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

#ifndef NDDS_STANDALONE_TYPE
System::String^ ChocolateLotStateTypeSupport::data_to_string(
    ChocolateLotState ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ ChocolateLotStateTypeSupport::data_to_string(
    ChocolateLotState ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}
#endif

DDS::TypeCode^ ChocolateLotStateTypeSupport::get_typecode() {
    #ifndef NDDS_STANDALONE_TYPE
    return  ChocolateLotState::get_typecode();
    #else
    return nullptr;
    #endif
}

System::String^ ChocolateLotStateTypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ ChocolateLotStateTypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ ChocolateLotStateTypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew ChocolateLotStateDataReader(impl);
}

DDS::DataWriter^ ChocolateLotStateTypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew ChocolateLotStateDataWriter(impl);
}

ChocolateLotStateTypeSupport^
ChocolateLotStateTypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew ChocolateLotStateTypeSupport();
    }
    return _singleton;
}

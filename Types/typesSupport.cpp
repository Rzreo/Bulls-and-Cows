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
// BAC_CONNECT_INIT_MESSAGEDataWriter
// ---------------------------------------------------------------------------

BAC_CONNECT_INIT_MESSAGEDataWriter::BAC_CONNECT_INIT_MESSAGEDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<BAC_CONNECT_INIT_MESSAGE^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BAC_CONNECT_INIT_MESSAGEDataReader
// ---------------------------------------------------------------------------

BAC_CONNECT_INIT_MESSAGEDataReader::BAC_CONNECT_INIT_MESSAGEDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<BAC_CONNECT_INIT_MESSAGE^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BAC_CONNECT_INIT_MESSAGETypeSupport
// ---------------------------------------------------------------------------

BAC_CONNECT_INIT_MESSAGETypeSupport::BAC_CONNECT_INIT_MESSAGETypeSupport()
: DDS::TypedTypeSupport<BAC_CONNECT_INIT_MESSAGE^>(
    BAC_CONNECT_INIT_MESSAGEPlugin::get_instance()) {

    _type_plugin = BAC_CONNECT_INIT_MESSAGEPlugin::get_instance();
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

BAC_CONNECT_INIT_MESSAGE^ BAC_CONNECT_INIT_MESSAGETypeSupport::create_data() {
    return gcnew BAC_CONNECT_INIT_MESSAGE();
}

BAC_CONNECT_INIT_MESSAGE^ BAC_CONNECT_INIT_MESSAGETypeSupport::create_data_untyped() {
    return create_data();
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::delete_data(
    BAC_CONNECT_INIT_MESSAGE^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::print_data(BAC_CONNECT_INIT_MESSAGE^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::copy_data(
    BAC_CONNECT_INIT_MESSAGE^ dst, BAC_CONNECT_INIT_MESSAGE^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    BAC_CONNECT_INIT_MESSAGE^ a_data,
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

void BAC_CONNECT_INIT_MESSAGETypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    BAC_CONNECT_INIT_MESSAGE^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void BAC_CONNECT_INIT_MESSAGETypeSupport::deserialize_data_from_cdr_buffer(
    BAC_CONNECT_INIT_MESSAGE^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

#ifndef NDDS_STANDALONE_TYPE
System::String^ BAC_CONNECT_INIT_MESSAGETypeSupport::data_to_string(
    BAC_CONNECT_INIT_MESSAGE ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ BAC_CONNECT_INIT_MESSAGETypeSupport::data_to_string(
    BAC_CONNECT_INIT_MESSAGE ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}
#endif

DDS::TypeCode^ BAC_CONNECT_INIT_MESSAGETypeSupport::get_typecode() {
    #ifndef NDDS_STANDALONE_TYPE
    return  BAC_CONNECT_INIT_MESSAGE::get_typecode();
    #else
    return nullptr;
    #endif
}

System::String^ BAC_CONNECT_INIT_MESSAGETypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ BAC_CONNECT_INIT_MESSAGETypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ BAC_CONNECT_INIT_MESSAGETypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew BAC_CONNECT_INIT_MESSAGEDataReader(impl);
}

DDS::DataWriter^ BAC_CONNECT_INIT_MESSAGETypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew BAC_CONNECT_INIT_MESSAGEDataWriter(impl);
}

BAC_CONNECT_INIT_MESSAGETypeSupport^
BAC_CONNECT_INIT_MESSAGETypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew BAC_CONNECT_INIT_MESSAGETypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// BAC_SERVER_CONNECT_MESSAGEDataWriter
// ---------------------------------------------------------------------------

BAC_SERVER_CONNECT_MESSAGEDataWriter::BAC_SERVER_CONNECT_MESSAGEDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<BAC_SERVER_CONNECT_MESSAGE^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BAC_SERVER_CONNECT_MESSAGEDataReader
// ---------------------------------------------------------------------------

BAC_SERVER_CONNECT_MESSAGEDataReader::BAC_SERVER_CONNECT_MESSAGEDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<BAC_SERVER_CONNECT_MESSAGE^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BAC_SERVER_CONNECT_MESSAGETypeSupport
// ---------------------------------------------------------------------------

BAC_SERVER_CONNECT_MESSAGETypeSupport::BAC_SERVER_CONNECT_MESSAGETypeSupport()
: DDS::TypedTypeSupport<BAC_SERVER_CONNECT_MESSAGE^>(
    BAC_SERVER_CONNECT_MESSAGEPlugin::get_instance()) {

    _type_plugin = BAC_SERVER_CONNECT_MESSAGEPlugin::get_instance();
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

BAC_SERVER_CONNECT_MESSAGE^ BAC_SERVER_CONNECT_MESSAGETypeSupport::create_data() {
    return gcnew BAC_SERVER_CONNECT_MESSAGE();
}

BAC_SERVER_CONNECT_MESSAGE^ BAC_SERVER_CONNECT_MESSAGETypeSupport::create_data_untyped() {
    return create_data();
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::delete_data(
    BAC_SERVER_CONNECT_MESSAGE^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::print_data(BAC_SERVER_CONNECT_MESSAGE^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::copy_data(
    BAC_SERVER_CONNECT_MESSAGE^ dst, BAC_SERVER_CONNECT_MESSAGE^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    BAC_SERVER_CONNECT_MESSAGE^ a_data,
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

void BAC_SERVER_CONNECT_MESSAGETypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    BAC_SERVER_CONNECT_MESSAGE^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void BAC_SERVER_CONNECT_MESSAGETypeSupport::deserialize_data_from_cdr_buffer(
    BAC_SERVER_CONNECT_MESSAGE^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

#ifndef NDDS_STANDALONE_TYPE
System::String^ BAC_SERVER_CONNECT_MESSAGETypeSupport::data_to_string(
    BAC_SERVER_CONNECT_MESSAGE ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ BAC_SERVER_CONNECT_MESSAGETypeSupport::data_to_string(
    BAC_SERVER_CONNECT_MESSAGE ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}
#endif

DDS::TypeCode^ BAC_SERVER_CONNECT_MESSAGETypeSupport::get_typecode() {
    #ifndef NDDS_STANDALONE_TYPE
    return  BAC_SERVER_CONNECT_MESSAGE::get_typecode();
    #else
    return nullptr;
    #endif
}

System::String^ BAC_SERVER_CONNECT_MESSAGETypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ BAC_SERVER_CONNECT_MESSAGETypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ BAC_SERVER_CONNECT_MESSAGETypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew BAC_SERVER_CONNECT_MESSAGEDataReader(impl);
}

DDS::DataWriter^ BAC_SERVER_CONNECT_MESSAGETypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew BAC_SERVER_CONNECT_MESSAGEDataWriter(impl);
}

BAC_SERVER_CONNECT_MESSAGETypeSupport^
BAC_SERVER_CONNECT_MESSAGETypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew BAC_SERVER_CONNECT_MESSAGETypeSupport();
    }
    return _singleton;
}

/* ========================================================================= */

// ---------------------------------------------------------------------------
// BAC_CLIENT_CONNECT_MESSAGEDataWriter
// ---------------------------------------------------------------------------

BAC_CLIENT_CONNECT_MESSAGEDataWriter::BAC_CLIENT_CONNECT_MESSAGEDataWriter(
    System::IntPtr impl) : DDS::TypedDataWriter<BAC_CLIENT_CONNECT_MESSAGE^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BAC_CLIENT_CONNECT_MESSAGEDataReader
// ---------------------------------------------------------------------------

BAC_CLIENT_CONNECT_MESSAGEDataReader::BAC_CLIENT_CONNECT_MESSAGEDataReader(
    System::IntPtr impl) : DDS::TypedDataReader<BAC_CLIENT_CONNECT_MESSAGE^>(impl) {
    // empty
}

// ---------------------------------------------------------------------------
// BAC_CLIENT_CONNECT_MESSAGETypeSupport
// ---------------------------------------------------------------------------

BAC_CLIENT_CONNECT_MESSAGETypeSupport::BAC_CLIENT_CONNECT_MESSAGETypeSupport()
: DDS::TypedTypeSupport<BAC_CLIENT_CONNECT_MESSAGE^>(
    BAC_CLIENT_CONNECT_MESSAGEPlugin::get_instance()) {

    _type_plugin = BAC_CLIENT_CONNECT_MESSAGEPlugin::get_instance();
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::register_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->register_type_untyped(participant, type_name);
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::unregister_type(
    DDS::DomainParticipant^ participant,
    System::String^ type_name) {

    get_instance()->unregister_type_untyped(participant, type_name);
}

BAC_CLIENT_CONNECT_MESSAGE^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::create_data() {
    return gcnew BAC_CLIENT_CONNECT_MESSAGE();
}

BAC_CLIENT_CONNECT_MESSAGE^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::create_data_untyped() {
    return create_data();
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::delete_data(
    BAC_CLIENT_CONNECT_MESSAGE^ a_data) {
    /* If the generated type does not implement IDisposable (the default),
    * the following will no a no-op.
    */
    delete a_data;
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::print_data(BAC_CLIENT_CONNECT_MESSAGE^ a_data) {
    get_instance()->_type_plugin->print_data(a_data, nullptr, 0);
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::copy_data(
    BAC_CLIENT_CONNECT_MESSAGE^ dst, BAC_CLIENT_CONNECT_MESSAGE^ src) {

    get_instance()->copy_data_untyped(dst, src);
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    BAC_CLIENT_CONNECT_MESSAGE^ a_data,
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

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::serialize_data_to_cdr_buffer(
    array<System::Byte>^ buffer,
    System::UInt32% length,
    BAC_CLIENT_CONNECT_MESSAGE^ a_data)
{
    if (!get_instance()->_type_plugin->serialize_to_cdr_buffer(buffer,length,a_data)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

void BAC_CLIENT_CONNECT_MESSAGETypeSupport::deserialize_data_from_cdr_buffer(
    BAC_CLIENT_CONNECT_MESSAGE^ a_data,
    array<System::Byte>^ buffer,
    System::UInt32 length)
{
    if (!get_instance()->_type_plugin->deserialize_from_cdr_buffer(a_data,buffer,length)) {
        throw gcnew Retcode_Error(DDS_RETCODE_ERROR);
    }
}

#ifndef NDDS_STANDALONE_TYPE
System::String^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::data_to_string(
    BAC_CLIENT_CONNECT_MESSAGE ^sample, 
    PrintFormatProperty ^formatProperty)
{
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}

System::String^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::data_to_string(
    BAC_CLIENT_CONNECT_MESSAGE ^sample)
{
    PrintFormatProperty ^formatProperty = gcnew PrintFormatProperty();
    return get_instance()->_type_plugin->data_to_string(
        sample, 
        formatProperty);
}
#endif

DDS::TypeCode^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::get_typecode() {
    #ifndef NDDS_STANDALONE_TYPE
    return  BAC_CLIENT_CONNECT_MESSAGE::get_typecode();
    #else
    return nullptr;
    #endif
}

System::String^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::get_type_name() {
    return TYPENAME;
}

System::String^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::get_type_name_untyped() {
    return TYPENAME;
}

DDS::DataReader^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::create_datareaderI(
    System::IntPtr impl) {

    return gcnew BAC_CLIENT_CONNECT_MESSAGEDataReader(impl);
}

DDS::DataWriter^ BAC_CLIENT_CONNECT_MESSAGETypeSupport::create_datawriterI(
    System::IntPtr impl) {

    return gcnew BAC_CLIENT_CONNECT_MESSAGEDataWriter(impl);
}

BAC_CLIENT_CONNECT_MESSAGETypeSupport^
BAC_CLIENT_CONNECT_MESSAGETypeSupport::get_instance() {
    if (_singleton == nullptr) {
        _singleton = gcnew BAC_CLIENT_CONNECT_MESSAGETypeSupport();
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

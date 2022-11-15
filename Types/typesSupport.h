/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from types.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

#include "types.h"

class DDSDataWriter;
class DDSDataReader;

// ---------------------------------------------------------------------------
// MessageTypeSupport
// ---------------------------------------------------------------------------

ref class MessagePlugin;

/* A collection of useful methods for dealing with objects of type
* Message.
*/
public ref class MessageTypeSupport
: public DDS::TypedTypeSupport<Message^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "Message";

    // --- Public Methods: ---------------------------------------------------
  public:
    /* Get the default name of this type.
    *
    * An application can choose to register a type under any name, so
    * calling this method is strictly optional.
    */
    static System::String^ get_type_name();

    /* Register this type with the given participant under the given logical
    * name. This type must be registered before a Topic can be created that
    * uses it.
    */
    static void register_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Unregister this type from the given participant, where it was
    * previously registered under the given name. No further Topic creation
    * using this type will be possible.
    *
    * Unregistration allows some middleware resources to be reclaimed.
    */
    static void unregister_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Create an instance of the Message type.
    */
    static Message^ create_data();

    /* If instances of the Message type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(Message^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(Message^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        Message^ dst_data,
        Message^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        Message^ a_data,
        System::Int16 representation);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        Message^ a_data);

    static void deserialize_data_from_cdr_buffer(
        Message^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    #ifndef NDDS_STANDALONE_TYPE
    static System::String^ data_to_string(
        Message ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        Message ^sample);
    #endif

    static DDS::TypeCode^ get_typecode();

    // --- Implementation: ---------------------------------------------------
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
  public:
    virtual System::String^ get_type_name_untyped() override;
    virtual DDS::DataReader^ create_datareaderI(
        System::IntPtr impl) override;
    virtual DDS::DataWriter^ create_datawriterI(
        System::IntPtr impl) override;

    virtual Message^ create_data_untyped() override;

  public:
    static MessageTypeSupport^ get_instance();

    MessageTypeSupport();

  private:
    static MessageTypeSupport^ _singleton;
    MessagePlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// MessageDataReader
// ---------------------------------------------------------------------------

/**
* A reader for the Message type.
*/
public ref class MessageDataReader :
public DDS::TypedDataReader<Message^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    MessageDataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// MessageDataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the Message user type.
*/
public ref class MessageDataWriter :
public DDS::TypedDataWriter<Message^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    MessageDataWriter(System::IntPtr impl);
};
// ---------------------------------------------------------------------------
// TemperatureTypeSupport
// ---------------------------------------------------------------------------

ref class TemperaturePlugin;

/* A collection of useful methods for dealing with objects of type
* Temperature.
*/
public ref class TemperatureTypeSupport
: public DDS::TypedTypeSupport<Temperature^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "Temperature";

    // --- Public Methods: ---------------------------------------------------
  public:
    /* Get the default name of this type.
    *
    * An application can choose to register a type under any name, so
    * calling this method is strictly optional.
    */
    static System::String^ get_type_name();

    /* Register this type with the given participant under the given logical
    * name. This type must be registered before a Topic can be created that
    * uses it.
    */
    static void register_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Unregister this type from the given participant, where it was
    * previously registered under the given name. No further Topic creation
    * using this type will be possible.
    *
    * Unregistration allows some middleware resources to be reclaimed.
    */
    static void unregister_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Create an instance of the Temperature type.
    */
    static Temperature^ create_data();

    /* If instances of the Temperature type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(Temperature^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(Temperature^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        Temperature^ dst_data,
        Temperature^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        Temperature^ a_data,
        System::Int16 representation);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        Temperature^ a_data);

    static void deserialize_data_from_cdr_buffer(
        Temperature^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    #ifndef NDDS_STANDALONE_TYPE
    static System::String^ data_to_string(
        Temperature ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        Temperature ^sample);
    #endif

    static DDS::TypeCode^ get_typecode();

    // --- Implementation: ---------------------------------------------------
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
  public:
    virtual System::String^ get_type_name_untyped() override;
    virtual DDS::DataReader^ create_datareaderI(
        System::IntPtr impl) override;
    virtual DDS::DataWriter^ create_datawriterI(
        System::IntPtr impl) override;

    virtual Temperature^ create_data_untyped() override;

  public:
    static TemperatureTypeSupport^ get_instance();

    TemperatureTypeSupport();

  private:
    static TemperatureTypeSupport^ _singleton;
    TemperaturePlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// TemperatureDataReader
// ---------------------------------------------------------------------------

/**
* A reader for the Temperature type.
*/
public ref class TemperatureDataReader :
public DDS::TypedDataReader<Temperature^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    TemperatureDataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// TemperatureDataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the Temperature user type.
*/
public ref class TemperatureDataWriter :
public DDS::TypedDataWriter<Temperature^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    TemperatureDataWriter(System::IntPtr impl);
};
// ---------------------------------------------------------------------------
// ChocolateLotStateTypeSupport
// ---------------------------------------------------------------------------

ref class ChocolateLotStatePlugin;

/* A collection of useful methods for dealing with objects of type
* ChocolateLotState.
*/
public ref class ChocolateLotStateTypeSupport
: public DDS::TypedTypeSupport<ChocolateLotState^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "ChocolateLotState";

    // --- Public Methods: ---------------------------------------------------
  public:
    /* Get the default name of this type.
    *
    * An application can choose to register a type under any name, so
    * calling this method is strictly optional.
    */
    static System::String^ get_type_name();

    /* Register this type with the given participant under the given logical
    * name. This type must be registered before a Topic can be created that
    * uses it.
    */
    static void register_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Unregister this type from the given participant, where it was
    * previously registered under the given name. No further Topic creation
    * using this type will be possible.
    *
    * Unregistration allows some middleware resources to be reclaimed.
    */
    static void unregister_type(
        DDS::DomainParticipant^ participant,
        System::String^ type_name);

    /* Create an instance of the ChocolateLotState type.
    */
    static ChocolateLotState^ create_data();

    /* If instances of the ChocolateLotState type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(ChocolateLotState^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(ChocolateLotState^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        ChocolateLotState^ dst_data,
        ChocolateLotState^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        ChocolateLotState^ a_data,
        System::Int16 representation);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        ChocolateLotState^ a_data);

    static void deserialize_data_from_cdr_buffer(
        ChocolateLotState^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    #ifndef NDDS_STANDALONE_TYPE
    static System::String^ data_to_string(
        ChocolateLotState ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        ChocolateLotState ^sample);
    #endif

    static DDS::TypeCode^ get_typecode();

    // --- Implementation: ---------------------------------------------------
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
  public:
    virtual System::String^ get_type_name_untyped() override;
    virtual DDS::DataReader^ create_datareaderI(
        System::IntPtr impl) override;
    virtual DDS::DataWriter^ create_datawriterI(
        System::IntPtr impl) override;

    virtual ChocolateLotState^ create_data_untyped() override;

  public:
    static ChocolateLotStateTypeSupport^ get_instance();

    ChocolateLotStateTypeSupport();

  private:
    static ChocolateLotStateTypeSupport^ _singleton;
    ChocolateLotStatePlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// ChocolateLotStateDataReader
// ---------------------------------------------------------------------------

/**
* A reader for the ChocolateLotState type.
*/
public ref class ChocolateLotStateDataReader :
public DDS::TypedDataReader<ChocolateLotState^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    ChocolateLotStateDataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// ChocolateLotStateDataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the ChocolateLotState user type.
*/
public ref class ChocolateLotStateDataWriter :
public DDS::TypedDataWriter<ChocolateLotState^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    ChocolateLotStateDataWriter(System::IntPtr impl);
};

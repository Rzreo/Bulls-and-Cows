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
// BAS_ROOM_DATATypeSupport
// ---------------------------------------------------------------------------

ref class BAS_ROOM_DATAPlugin;

/* A collection of useful methods for dealing with objects of type
* BAS_ROOM_DATA.
*/
public ref class BAS_ROOM_DATATypeSupport
: public DDS::TypedTypeSupport<BAS_ROOM_DATA^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "BAS_ROOM_DATA";

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

    /* Create an instance of the BAS_ROOM_DATA type.
    */
    static BAS_ROOM_DATA^ create_data();

    /* If instances of the BAS_ROOM_DATA type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(BAS_ROOM_DATA^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(BAS_ROOM_DATA^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        BAS_ROOM_DATA^ dst_data,
        BAS_ROOM_DATA^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        BAS_ROOM_DATA^ a_data,
        System::Int16 representation);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        BAS_ROOM_DATA^ a_data);

    static void deserialize_data_from_cdr_buffer(
        BAS_ROOM_DATA^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    #ifndef NDDS_STANDALONE_TYPE
    static System::String^ data_to_string(
        BAS_ROOM_DATA ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        BAS_ROOM_DATA ^sample);
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

    virtual BAS_ROOM_DATA^ create_data_untyped() override;

  public:
    static BAS_ROOM_DATATypeSupport^ get_instance();

    BAS_ROOM_DATATypeSupport();

  private:
    static BAS_ROOM_DATATypeSupport^ _singleton;
    BAS_ROOM_DATAPlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// BAS_ROOM_DATADataReader
// ---------------------------------------------------------------------------

/**
* A reader for the BAS_ROOM_DATA type.
*/
public ref class BAS_ROOM_DATADataReader :
public DDS::TypedDataReader<BAS_ROOM_DATA^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    BAS_ROOM_DATADataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// BAS_ROOM_DATADataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the BAS_ROOM_DATA user type.
*/
public ref class BAS_ROOM_DATADataWriter :
public DDS::TypedDataWriter<BAS_ROOM_DATA^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    BAS_ROOM_DATADataWriter(System::IntPtr impl);
};
// ---------------------------------------------------------------------------
// BAC_CONNECT_INIT_MESSAGETypeSupport
// ---------------------------------------------------------------------------

ref class BAC_CONNECT_INIT_MESSAGEPlugin;

/* A collection of useful methods for dealing with objects of type
* BAC_CONNECT_INIT_MESSAGE.
*/
public ref class BAC_CONNECT_INIT_MESSAGETypeSupport
: public DDS::TypedTypeSupport<BAC_CONNECT_INIT_MESSAGE^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "BAC_CONNECT_INIT_MESSAGE";

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

    /* Create an instance of the BAC_CONNECT_INIT_MESSAGE type.
    */
    static BAC_CONNECT_INIT_MESSAGE^ create_data();

    /* If instances of the BAC_CONNECT_INIT_MESSAGE type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(BAC_CONNECT_INIT_MESSAGE^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(BAC_CONNECT_INIT_MESSAGE^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        BAC_CONNECT_INIT_MESSAGE^ dst_data,
        BAC_CONNECT_INIT_MESSAGE^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        BAC_CONNECT_INIT_MESSAGE^ a_data,
        System::Int16 representation);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        BAC_CONNECT_INIT_MESSAGE^ a_data);

    static void deserialize_data_from_cdr_buffer(
        BAC_CONNECT_INIT_MESSAGE^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    #ifndef NDDS_STANDALONE_TYPE
    static System::String^ data_to_string(
        BAC_CONNECT_INIT_MESSAGE ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        BAC_CONNECT_INIT_MESSAGE ^sample);
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

    virtual BAC_CONNECT_INIT_MESSAGE^ create_data_untyped() override;

  public:
    static BAC_CONNECT_INIT_MESSAGETypeSupport^ get_instance();

    BAC_CONNECT_INIT_MESSAGETypeSupport();

  private:
    static BAC_CONNECT_INIT_MESSAGETypeSupport^ _singleton;
    BAC_CONNECT_INIT_MESSAGEPlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// BAC_CONNECT_INIT_MESSAGEDataReader
// ---------------------------------------------------------------------------

/**
* A reader for the BAC_CONNECT_INIT_MESSAGE type.
*/
public ref class BAC_CONNECT_INIT_MESSAGEDataReader :
public DDS::TypedDataReader<BAC_CONNECT_INIT_MESSAGE^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    BAC_CONNECT_INIT_MESSAGEDataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// BAC_CONNECT_INIT_MESSAGEDataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the BAC_CONNECT_INIT_MESSAGE user type.
*/
public ref class BAC_CONNECT_INIT_MESSAGEDataWriter :
public DDS::TypedDataWriter<BAC_CONNECT_INIT_MESSAGE^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    BAC_CONNECT_INIT_MESSAGEDataWriter(System::IntPtr impl);
};
// ---------------------------------------------------------------------------
// BAC_CONNECT_MESSAGETypeSupport
// ---------------------------------------------------------------------------

ref class BAC_CONNECT_MESSAGEPlugin;

/* A collection of useful methods for dealing with objects of type
* BAC_CONNECT_MESSAGE.
*/
public ref class BAC_CONNECT_MESSAGETypeSupport
: public DDS::TypedTypeSupport<BAC_CONNECT_MESSAGE^> {
    // --- Type name: --------------------------------------------------------
  public:
    static System::String^ TYPENAME = "BAC_CONNECT_MESSAGE";

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

    /* Create an instance of the BAC_CONNECT_MESSAGE type.
    */
    static BAC_CONNECT_MESSAGE^ create_data();

    /* If instances of the BAC_CONNECT_MESSAGE type require any
    * explicit finalization, perform it now on the given sample.
    */
    static void delete_data(BAC_CONNECT_MESSAGE^ data);

    /* Write the contents of the data sample to standard out.
    */
    static void print_data(BAC_CONNECT_MESSAGE^ a_data);

    /* Perform a deep copy of the contents of one data sample over those of
    * another, overwriting it.
    */
    static void copy_data(
        BAC_CONNECT_MESSAGE^ dst_data,
        BAC_CONNECT_MESSAGE^ src_data);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        BAC_CONNECT_MESSAGE^ a_data,
        System::Int16 representation);

    static void serialize_data_to_cdr_buffer(
        array<System::Byte>^ buffer,
        System::UInt32% length,
        BAC_CONNECT_MESSAGE^ a_data);

    static void deserialize_data_from_cdr_buffer(
        BAC_CONNECT_MESSAGE^ a_data,
        array<System::Byte>^ buffer,
        System::UInt32 length);

    #ifndef NDDS_STANDALONE_TYPE
    static System::String^ data_to_string(
        BAC_CONNECT_MESSAGE ^sample,
        PrintFormatProperty ^property);

    static System::String^ data_to_string(
        BAC_CONNECT_MESSAGE ^sample);
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

    virtual BAC_CONNECT_MESSAGE^ create_data_untyped() override;

  public:
    static BAC_CONNECT_MESSAGETypeSupport^ get_instance();

    BAC_CONNECT_MESSAGETypeSupport();

  private:
    static BAC_CONNECT_MESSAGETypeSupport^ _singleton;
    BAC_CONNECT_MESSAGEPlugin^ _type_plugin;
};

// ---------------------------------------------------------------------------
// BAC_CONNECT_MESSAGEDataReader
// ---------------------------------------------------------------------------

/**
* A reader for the BAC_CONNECT_MESSAGE type.
*/
public ref class BAC_CONNECT_MESSAGEDataReader :
public DDS::TypedDataReader<BAC_CONNECT_MESSAGE^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    BAC_CONNECT_MESSAGEDataReader(System::IntPtr impl);
};

// ---------------------------------------------------------------------------
// BAC_CONNECT_MESSAGEDataWriter
// ---------------------------------------------------------------------------

/**
* A writer for the BAC_CONNECT_MESSAGE user type.
*/
public ref class BAC_CONNECT_MESSAGEDataWriter :
public DDS::TypedDataWriter<BAC_CONNECT_MESSAGE^> {
    /* The following code is for the use of the middleware infrastructure.
    * Applications are not expected to call it directly.
    */
    internal:
    BAC_CONNECT_MESSAGEDataWriter(System::IntPtr impl);
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

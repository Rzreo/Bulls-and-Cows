
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from types.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

struct DDS_TypeCode;

using namespace System;
using namespace DDS;

public ref class CHOCOLATE_LOT_STATE_TOPIC sealed {
  public:
    static const System::String^ VALUE =
    "ChocolateLotState";

  private:
    CHOCOLATE_LOT_STATE_TOPIC() {}
};

public ref class CHOCOLATE_TEMPERATURE_TOPIC sealed {
  public:
    static const System::String^ VALUE =
    "ChocolateTemperature";

  private:
    CHOCOLATE_TEMPERATURE_TOPIC() {}
};

public ref class ROOM_ID_CLIENT_REQUIRE sealed {
  public:
    static const System::String^ VALUE =
    "GiveMeRoom";

  private:
    ROOM_ID_CLIENT_REQUIRE() {}
};

public ref class MAX_STRING_LEN sealed {
  public:
    static const System::UInt32 VALUE =
    256;

  private:
    MAX_STRING_LEN() {}
};

public ref class ID_STRING_LEN sealed {
  public:
    static const System::UInt32 VALUE =
    24;

  private:
    ID_STRING_LEN() {}
};

public ref struct BAC_AVAILABLE_IDs
:  public DDS::ICopyable<BAC_AVAILABLE_IDs^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ ID1;
    System::String^ ID2;
    System::String^ ID3;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    BAC_AVAILABLE_IDs();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(BAC_AVAILABLE_IDs^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class BAC_AVAILABLE_IDs

public ref class BAC_AVAILABLE_IDsSeq sealed
: public DDS::UserRefSequence<BAC_AVAILABLE_IDs^> {
  public:
    BAC_AVAILABLE_IDsSeq() :
        DDS::UserRefSequence<BAC_AVAILABLE_IDs^>() {
            // empty
    }
    BAC_AVAILABLE_IDsSeq(System::Int32 max) :
        DDS::UserRefSequence<BAC_AVAILABLE_IDs^>(max) {
            // empty
    }
    BAC_AVAILABLE_IDsSeq(BAC_AVAILABLE_IDsSeq^ src) :
        DDS::UserRefSequence<BAC_AVAILABLE_IDs^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* BAC_AVAILABLE_IDs_get_typecode();

#endif

public ref struct BAC_CREATE_ROOM
:  public DDS::ICopyable<BAC_CREATE_ROOM^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ ROOM_ID;
    System::String^ CLIENT_ID;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    BAC_CREATE_ROOM();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(BAC_CREATE_ROOM^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class BAC_CREATE_ROOM

public ref class BAC_CREATE_ROOMSeq sealed
: public DDS::UserRefSequence<BAC_CREATE_ROOM^> {
  public:
    BAC_CREATE_ROOMSeq() :
        DDS::UserRefSequence<BAC_CREATE_ROOM^>() {
            // empty
    }
    BAC_CREATE_ROOMSeq(System::Int32 max) :
        DDS::UserRefSequence<BAC_CREATE_ROOM^>(max) {
            // empty
    }
    BAC_CREATE_ROOMSeq(BAC_CREATE_ROOMSeq^ src) :
        DDS::UserRefSequence<BAC_CREATE_ROOM^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* BAC_CREATE_ROOM_get_typecode();

#endif

public ref struct Message
:  public DDS::ICopyable<Message^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ msg;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    Message();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(Message^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class Message

public ref class MessageSeq sealed
: public DDS::UserRefSequence<Message^> {
  public:
    MessageSeq() :
        DDS::UserRefSequence<Message^>() {
            // empty
    }
    MessageSeq(System::Int32 max) :
        DDS::UserRefSequence<Message^>(max) {
            // empty
    }
    MessageSeq(MessageSeq^ src) :
        DDS::UserRefSequence<Message^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* Message_get_typecode();

#endif

public ref struct Temperature
:  public DDS::ICopyable<Temperature^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ sensor_id;
    System::Int32 degrees;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    Temperature();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(Temperature^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class Temperature

public ref class TemperatureSeq sealed
: public DDS::UserRefSequence<Temperature^> {
  public:
    TemperatureSeq() :
        DDS::UserRefSequence<Temperature^>() {
            // empty
    }
    TemperatureSeq(System::Int32 max) :
        DDS::UserRefSequence<Temperature^>(max) {
            // empty
    }
    TemperatureSeq(TemperatureSeq^ src) :
        DDS::UserRefSequence<Temperature^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* Temperature_get_typecode();

#endif

public enum class StationKind : System::Int32 {
    INVALID_CONTROLLER ,
    COCOA_BUTTER_CONTROLLER ,
    SUGAR_CONTROLLER ,
    MILK_CONTROLLER ,
    VANILLA_CONTROLLER ,
    TEMPERING_CONTROLLER 
};

StationKind StationKind_get_default_value();

public ref class StationKindHelper {
  public:
    static StationKind StationKind_get_default_value();
};

public ref class StationKindSeq
: public DDS::UserValueSequence<StationKind> {
  public:
    StationKindSeq() :
        DDS::UserValueSequence<StationKind>() {
            // empty
    }
    StationKindSeq(System::Int32 max) :
        DDS::UserValueSequence<StationKind>(max) {
            // empty
    }
    StationKindSeq(StationKindSeq^ src) :
        DDS::UserValueSequence<StationKind>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* StationKind_get_typecode();

#endif

public enum class LotStatusKind : System::Int32 {
    WAITING ,
    PROCESSING ,
    COMPLETED 
};

LotStatusKind LotStatusKind_get_default_value();

public ref class LotStatusKindHelper {
  public:
    static LotStatusKind LotStatusKind_get_default_value();
};

public ref class LotStatusKindSeq
: public DDS::UserValueSequence<LotStatusKind> {
  public:
    LotStatusKindSeq() :
        DDS::UserValueSequence<LotStatusKind>() {
            // empty
    }
    LotStatusKindSeq(System::Int32 max) :
        DDS::UserValueSequence<LotStatusKind>(max) {
            // empty
    }
    LotStatusKindSeq(LotStatusKindSeq^ src) :
        DDS::UserValueSequence<LotStatusKind>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* LotStatusKind_get_typecode();

#endif

public ref struct ChocolateLotState
:  public DDS::ICopyable<ChocolateLotState^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::UInt32 lot_id;
    StationKind station;
    StationKind next_station;
    LotStatusKind lot_status;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    ChocolateLotState();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(ChocolateLotState^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class ChocolateLotState

public ref class ChocolateLotStateSeq sealed
: public DDS::UserRefSequence<ChocolateLotState^> {
  public:
    ChocolateLotStateSeq() :
        DDS::UserRefSequence<ChocolateLotState^>() {
            // empty
    }
    ChocolateLotStateSeq(System::Int32 max) :
        DDS::UserRefSequence<ChocolateLotState^>(max) {
            // empty
    }
    ChocolateLotStateSeq(ChocolateLotStateSeq^ src) :
        DDS::UserRefSequence<ChocolateLotState^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* ChocolateLotState_get_typecode();

#endif


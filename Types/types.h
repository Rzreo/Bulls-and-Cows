
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

public ref class MAX_STRING_LEN sealed {
  public:
    static const System::UInt32 VALUE =
    256;

  private:
    MAX_STRING_LEN() {}
};

public ref struct BAC_CONNECT
:  public DDS::ICopyable<BAC_CONNECT^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ ID;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    BAC_CONNECT();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(BAC_CONNECT^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class BAC_CONNECT

public ref class BAC_CONNECTSeq sealed
: public DDS::UserRefSequence<BAC_CONNECT^> {
  public:
    BAC_CONNECTSeq() :
        DDS::UserRefSequence<BAC_CONNECT^>() {
            // empty
    }
    BAC_CONNECTSeq(System::Int32 max) :
        DDS::UserRefSequence<BAC_CONNECT^>(max) {
            // empty
    }
    BAC_CONNECTSeq(BAC_CONNECTSeq^ src) :
        DDS::UserRefSequence<BAC_CONNECT^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* BAC_CONNECT_get_typecode();

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


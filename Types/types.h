
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

public ref class MSG_STRING_LEN sealed {
  public:
    static const System::UInt32 VALUE =
    1024;

  private:
    MSG_STRING_LEN() {}
};

public enum class CLIENT_CONNECT_MESSAGE_TYPE : System::Int32 {
    CONNECTTING ,
    CREATE_ROOM ,
    REQUEST_ROOM_LIST ,
    ENTER_ROOM ,
    REQUEST_ROOM_DATA 
};

CLIENT_CONNECT_MESSAGE_TYPE CLIENT_CONNECT_MESSAGE_TYPE_get_default_value();

public ref class CLIENT_CONNECT_MESSAGE_TYPEHelper {
  public:
    static CLIENT_CONNECT_MESSAGE_TYPE CLIENT_CONNECT_MESSAGE_TYPE_get_default_value();
};

public ref class CLIENT_CONNECT_MESSAGE_TYPESeq
: public DDS::UserValueSequence<CLIENT_CONNECT_MESSAGE_TYPE> {
  public:
    CLIENT_CONNECT_MESSAGE_TYPESeq() :
        DDS::UserValueSequence<CLIENT_CONNECT_MESSAGE_TYPE>() {
            // empty
    }
    CLIENT_CONNECT_MESSAGE_TYPESeq(System::Int32 max) :
        DDS::UserValueSequence<CLIENT_CONNECT_MESSAGE_TYPE>(max) {
            // empty
    }
    CLIENT_CONNECT_MESSAGE_TYPESeq(CLIENT_CONNECT_MESSAGE_TYPESeq^ src) :
        DDS::UserValueSequence<CLIENT_CONNECT_MESSAGE_TYPE>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* CLIENT_CONNECT_MESSAGE_TYPE_get_typecode();

#endif

public enum class SERVER_CONNECT_MESSAGE_TYPE : System::Int32 {
    SERVER_CONNECT_SUCCESS ,
    CREATE_ROOM_SUCCESS ,
    SEND_ROOM_LIST ,
    ENTER_ROOM_SUCCESS ,
    SEND_ROOM_DATA 
};

SERVER_CONNECT_MESSAGE_TYPE SERVER_CONNECT_MESSAGE_TYPE_get_default_value();

public ref class SERVER_CONNECT_MESSAGE_TYPEHelper {
  public:
    static SERVER_CONNECT_MESSAGE_TYPE SERVER_CONNECT_MESSAGE_TYPE_get_default_value();
};

public ref class SERVER_CONNECT_MESSAGE_TYPESeq
: public DDS::UserValueSequence<SERVER_CONNECT_MESSAGE_TYPE> {
  public:
    SERVER_CONNECT_MESSAGE_TYPESeq() :
        DDS::UserValueSequence<SERVER_CONNECT_MESSAGE_TYPE>() {
            // empty
    }
    SERVER_CONNECT_MESSAGE_TYPESeq(System::Int32 max) :
        DDS::UserValueSequence<SERVER_CONNECT_MESSAGE_TYPE>(max) {
            // empty
    }
    SERVER_CONNECT_MESSAGE_TYPESeq(SERVER_CONNECT_MESSAGE_TYPESeq^ src) :
        DDS::UserValueSequence<SERVER_CONNECT_MESSAGE_TYPE>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* SERVER_CONNECT_MESSAGE_TYPE_get_typecode();

#endif

public ref struct BAC_CONNECT_INIT_MESSAGE
:  public DDS::ICopyable<BAC_CONNECT_INIT_MESSAGE^> {
    // --- Declared members: -------------------------------------------------
  public: 

    System::String^ CLIENT_ID;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    BAC_CONNECT_INIT_MESSAGE();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(BAC_CONNECT_INIT_MESSAGE^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class BAC_CONNECT_INIT_MESSAGE

public ref class BAC_CONNECT_INIT_MESSAGESeq sealed
: public DDS::UserRefSequence<BAC_CONNECT_INIT_MESSAGE^> {
  public:
    BAC_CONNECT_INIT_MESSAGESeq() :
        DDS::UserRefSequence<BAC_CONNECT_INIT_MESSAGE^>() {
            // empty
    }
    BAC_CONNECT_INIT_MESSAGESeq(System::Int32 max) :
        DDS::UserRefSequence<BAC_CONNECT_INIT_MESSAGE^>(max) {
            // empty
    }
    BAC_CONNECT_INIT_MESSAGESeq(BAC_CONNECT_INIT_MESSAGESeq^ src) :
        DDS::UserRefSequence<BAC_CONNECT_INIT_MESSAGE^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* BAC_CONNECT_INIT_MESSAGE_get_typecode();

#endif

public ref struct BAC_SERVER_CONNECT_MESSAGE
:  public DDS::ICopyable<BAC_SERVER_CONNECT_MESSAGE^> {
    // --- Declared members: -------------------------------------------------
  public: 

    SERVER_CONNECT_MESSAGE_TYPE type;
    System::String^ msg;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    BAC_SERVER_CONNECT_MESSAGE();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(BAC_SERVER_CONNECT_MESSAGE^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class BAC_SERVER_CONNECT_MESSAGE

public ref class BAC_SERVER_CONNECT_MESSAGESeq sealed
: public DDS::UserRefSequence<BAC_SERVER_CONNECT_MESSAGE^> {
  public:
    BAC_SERVER_CONNECT_MESSAGESeq() :
        DDS::UserRefSequence<BAC_SERVER_CONNECT_MESSAGE^>() {
            // empty
    }
    BAC_SERVER_CONNECT_MESSAGESeq(System::Int32 max) :
        DDS::UserRefSequence<BAC_SERVER_CONNECT_MESSAGE^>(max) {
            // empty
    }
    BAC_SERVER_CONNECT_MESSAGESeq(BAC_SERVER_CONNECT_MESSAGESeq^ src) :
        DDS::UserRefSequence<BAC_SERVER_CONNECT_MESSAGE^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* BAC_SERVER_CONNECT_MESSAGE_get_typecode();

#endif

public ref struct BAC_CLIENT_CONNECT_MESSAGE
:  public DDS::ICopyable<BAC_CLIENT_CONNECT_MESSAGE^> {
    // --- Declared members: -------------------------------------------------
  public: 

    CLIENT_CONNECT_MESSAGE_TYPE type;
    System::String^ msg;

    // --- Static constants: -------------------------------------    
  public:

    // --- Constructors and destructors: -------------------------------------
  public:
    BAC_CLIENT_CONNECT_MESSAGE();

    // --- Utility methods: --------------------------------------------------
  public:

    virtual void clear() ;

    virtual System::Boolean copy_from(BAC_CLIENT_CONNECT_MESSAGE^ src);

    virtual System::Boolean Equals(System::Object^ other) override;
    #ifndef NDDS_STANDALONE_TYPE
    static DDS::TypeCode^ get_typecode();

  private:
    static DDS::TypeCode^ _typecode;
    #endif

}; // class BAC_CLIENT_CONNECT_MESSAGE

public ref class BAC_CLIENT_CONNECT_MESSAGESeq sealed
: public DDS::UserRefSequence<BAC_CLIENT_CONNECT_MESSAGE^> {
  public:
    BAC_CLIENT_CONNECT_MESSAGESeq() :
        DDS::UserRefSequence<BAC_CLIENT_CONNECT_MESSAGE^>() {
            // empty
    }
    BAC_CLIENT_CONNECT_MESSAGESeq(System::Int32 max) :
        DDS::UserRefSequence<BAC_CLIENT_CONNECT_MESSAGE^>(max) {
            // empty
    }
    BAC_CLIENT_CONNECT_MESSAGESeq(BAC_CLIENT_CONNECT_MESSAGESeq^ src) :
        DDS::UserRefSequence<BAC_CLIENT_CONNECT_MESSAGE^>(src) {
            // empty
    }
};

#ifndef NDDS_STANDALONE_TYPE

#define NDDSUSERDllExport

NDDSUSERDllExport DDS_TypeCode* BAC_CLIENT_CONNECT_MESSAGE_get_typecode();

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


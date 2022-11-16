/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from types.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#pragma once

#include "types.h"

/* ------------------------------------------------------------------------
* Enum Type: CLIENT_CONNECT_MESSAGE_TYPE
* ------------------------------------------------------------------------ */

public ref class CLIENT_CONNECT_MESSAGE_TYPEPlugin {
    // --- (De)Serialization Methods: --------------------------------------------
  public:
    System::Boolean serialize(
        TypePluginEndpointData^ endpoint_data,
        CLIENT_CONNECT_MESSAGE_TYPE sample,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos);

    System::Boolean deserialize_sample(
        TypePluginEndpointData^ endpoint_data,
        CLIENT_CONNECT_MESSAGE_TYPE% sample,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_sample, 
        System::Object^ endpoint_plugin_qos);

    System::Boolean skip(
        TypePluginEndpointData^ endpoint_data,
        CdrStream% stream,
        System::Boolean skip_encapsulation,
        System::Boolean skip_sample, 
        System::Object^ endpoint_plugin_qos);

    System::UInt32 get_serialized_sample_max_size(
        TypePluginEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 size);

    System::UInt32 get_serialized_sample_min_size(
        TypePluginEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 size);

    System::UInt32 get_serialized_sample_size(
        TypePluginEndpointData^ endpoint_data,
        Boolean include_encapsulation,
        UInt16 encapsulation_id,
        UInt32 current_alignment,
        CLIENT_CONNECT_MESSAGE_TYPE sample);

    // --- Key Management functions: ---------------------------------------------
  public:
    System::Boolean serialize_key(
        TypePluginEndpointData^ endpoint_data,
        CLIENT_CONNECT_MESSAGE_TYPE key,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos);

    System::Boolean serialize_key_for_keyhash(
        TypePluginEndpointData^ endpoint_data,
        CLIENT_CONNECT_MESSAGE_TYPE key,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos);

    System::Boolean deserialize_key_sample(
        TypePluginEndpointData^ endpoint_data,
        CLIENT_CONNECT_MESSAGE_TYPE% key,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_sample,
        System::Object^ endpoint_plugin_qos);

    System::UInt32 get_serialized_key_max_size(
        TypePluginEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 current_alignment);

    System::UInt32 get_serialized_key_for_keyhash_max_size(
        TypePluginEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 current_alignment);

    System::Boolean serialized_sample_to_key(
        TypePluginEndpointData^ endpoint_data,
        CLIENT_CONNECT_MESSAGE_TYPE% sample,
        CdrStream% stream, 
        Boolean deserialize_encapsulation,  
        Boolean deserialize_key, 
        Object^ endpoint_plugin_qos);

    // --- Support functions: ----------------------------------------------------
  public:
    void print_data(
        CLIENT_CONNECT_MESSAGE_TYPE sample,
        System::String^ desc,
        System::UInt32 indent_level);

    // ---  Plug-in lifecycle management methods: --------------------------------
  public:
    static CLIENT_CONNECT_MESSAGE_TYPEPlugin^ get_instance();

    static void dispose();

  private:
    CLIENT_CONNECT_MESSAGE_TYPEPlugin() { /*empty*/ }

    static CLIENT_CONNECT_MESSAGE_TYPEPlugin^ _singleton;
};        

/* ------------------------------------------------------------------------
* Type: BAC_CONNECT_INIT_MESSAGE
* ------------------------------------------------------------------------ */

public ref class BAC_CONNECT_INIT_MESSAGEPlugin :
DefaultTypePlugin<BAC_CONNECT_INIT_MESSAGE^> {
    // --- Support methods: ------------------------------------------------------
  public:
    void print_data(
        BAC_CONNECT_INIT_MESSAGE^ sample,
        System::String^ desc,
        System::UInt32 indent);

    // --- (De)Serialize methods: ------------------------------------------------
  public:
    virtual System::Boolean serialize(
        TypePluginDefaultEndpointData^ endpoint_data,
        BAC_CONNECT_INIT_MESSAGE^ sample,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    virtual System::Boolean deserialize_sample(
        TypePluginDefaultEndpointData^ endpoint_data,
        BAC_CONNECT_INIT_MESSAGE^ sample,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_sample, 
        System::Object^ endpoint_plugin_qos) override;

    System::Boolean skip(
        TypePluginDefaultEndpointData^ endpoint_data,
        CdrStream% stream,
        System::Boolean skip_encapsulation,  
        System::Boolean skip_sample, 
        System::Object^ endpoint_plugin_qos);

    virtual System::UInt32 get_serialized_sample_max_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 size) override;

    virtual System::UInt32 get_serialized_sample_min_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 size) override;

    virtual System::UInt32 get_serialized_sample_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        Boolean include_encapsulation,
        UInt16 encapsulation_id,
        UInt32 current_alignment,
        BAC_CONNECT_INIT_MESSAGE^ sample) override;

    // ---  Key Management functions: --------------------------------------------
  public:
    virtual System::UInt32 get_serialized_key_max_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 current_alignment) override;

    virtual System::UInt32 get_serialized_key_for_keyhash_max_size(
        TypePluginDefaultEndpointData^ endpoint_data,
        System::Boolean include_encapsulation,
        System::UInt16  encapsulation_id,
        System::UInt32 current_alignment) override;     

    virtual System::Boolean serialize_key(
        TypePluginDefaultEndpointData^ endpoint_data,
        BAC_CONNECT_INIT_MESSAGE^ key,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    virtual System::Boolean serialize_key_for_keyhash(
        TypePluginDefaultEndpointData^ endpoint_data,
        BAC_CONNECT_INIT_MESSAGE^ key,
        CdrStream% stream,
        System::Boolean serialize_encapsulation,
        System::UInt16  encapsulation_id,
        System::Boolean serialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    virtual System::Boolean deserialize_key_sample(
        TypePluginDefaultEndpointData^ endpoint_data,
        BAC_CONNECT_INIT_MESSAGE^ key,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_sample,
        System::Object^ endpoint_plugin_qos) override;

    System::Boolean serialized_sample_to_key(
        TypePluginDefaultEndpointData^ endpoint_data,
        BAC_CONNECT_INIT_MESSAGE^ sample,
        CdrStream% stream,
        System::Boolean deserialize_encapsulation,
        System::Boolean deserialize_key,
        System::Object^ endpoint_plugin_qos);

    // ---  Plug-in lifecycle management methods: --------------------------------
  public:
    static BAC_CONNECT_INIT_MESSAGEPlugin^ get_instance();

    static void dispose();

  private:
    BAC_CONNECT_INIT_MESSAGEPlugin()
    : DefaultTypePlugin(
        "BAC_CONNECT_INIT_MESSAGE",

        false, // not keyed    
        false, // use RTPS-compliant alignment
        #ifndef NDDS_STANDALONE_TYPE
        BAC_CONNECT_INIT_MESSAGE::get_typecode()) {
        #else
        nullptr) {
            #endif
            // empty
        }

        static BAC_CONNECT_INIT_MESSAGEPlugin^ _singleton;
    };

    /* ------------------------------------------------------------------------
    * Type: BAC_CONNECT_MESSAGE
    * ------------------------------------------------------------------------ */

    public ref class BAC_CONNECT_MESSAGEPlugin :
    DefaultTypePlugin<BAC_CONNECT_MESSAGE^> {
        // --- Support methods: ------------------------------------------------------
      public:
        void print_data(
            BAC_CONNECT_MESSAGE^ sample,
            System::String^ desc,
            System::UInt32 indent);

        // --- (De)Serialize methods: ------------------------------------------------
      public:
        virtual System::Boolean serialize(
            TypePluginDefaultEndpointData^ endpoint_data,
            BAC_CONNECT_MESSAGE^ sample,
            CdrStream% stream,
            System::Boolean serialize_encapsulation,
            System::UInt16  encapsulation_id,
            System::Boolean serialize_sample,
            System::Object^ endpoint_plugin_qos) override;

        virtual System::Boolean deserialize_sample(
            TypePluginDefaultEndpointData^ endpoint_data,
            BAC_CONNECT_MESSAGE^ sample,
            CdrStream% stream,
            System::Boolean deserialize_encapsulation,
            System::Boolean deserialize_sample, 
            System::Object^ endpoint_plugin_qos) override;

        System::Boolean skip(
            TypePluginDefaultEndpointData^ endpoint_data,
            CdrStream% stream,
            System::Boolean skip_encapsulation,  
            System::Boolean skip_sample, 
            System::Object^ endpoint_plugin_qos);

        virtual System::UInt32 get_serialized_sample_max_size(
            TypePluginDefaultEndpointData^ endpoint_data,
            System::Boolean include_encapsulation,
            System::UInt16  encapsulation_id,
            System::UInt32 size) override;

        virtual System::UInt32 get_serialized_sample_min_size(
            TypePluginDefaultEndpointData^ endpoint_data,
            System::Boolean include_encapsulation,
            System::UInt16  encapsulation_id,
            System::UInt32 size) override;

        virtual System::UInt32 get_serialized_sample_size(
            TypePluginDefaultEndpointData^ endpoint_data,
            Boolean include_encapsulation,
            UInt16 encapsulation_id,
            UInt32 current_alignment,
            BAC_CONNECT_MESSAGE^ sample) override;

        // ---  Key Management functions: --------------------------------------------
      public:
        virtual System::UInt32 get_serialized_key_max_size(
            TypePluginDefaultEndpointData^ endpoint_data,
            System::Boolean include_encapsulation,
            System::UInt16  encapsulation_id,
            System::UInt32 current_alignment) override;

        virtual System::UInt32 get_serialized_key_for_keyhash_max_size(
            TypePluginDefaultEndpointData^ endpoint_data,
            System::Boolean include_encapsulation,
            System::UInt16  encapsulation_id,
            System::UInt32 current_alignment) override;     

        virtual System::Boolean serialize_key(
            TypePluginDefaultEndpointData^ endpoint_data,
            BAC_CONNECT_MESSAGE^ key,
            CdrStream% stream,
            System::Boolean serialize_encapsulation,
            System::UInt16  encapsulation_id,
            System::Boolean serialize_sample,
            System::Object^ endpoint_plugin_qos) override;

        virtual System::Boolean serialize_key_for_keyhash(
            TypePluginDefaultEndpointData^ endpoint_data,
            BAC_CONNECT_MESSAGE^ key,
            CdrStream% stream,
            System::Boolean serialize_encapsulation,
            System::UInt16  encapsulation_id,
            System::Boolean serialize_sample,
            System::Object^ endpoint_plugin_qos) override;

        virtual System::Boolean deserialize_key_sample(
            TypePluginDefaultEndpointData^ endpoint_data,
            BAC_CONNECT_MESSAGE^ key,
            CdrStream% stream,
            System::Boolean deserialize_encapsulation,
            System::Boolean deserialize_sample,
            System::Object^ endpoint_plugin_qos) override;

        System::Boolean serialized_sample_to_key(
            TypePluginDefaultEndpointData^ endpoint_data,
            BAC_CONNECT_MESSAGE^ sample,
            CdrStream% stream,
            System::Boolean deserialize_encapsulation,
            System::Boolean deserialize_key,
            System::Object^ endpoint_plugin_qos);

        // ---  Plug-in lifecycle management methods: --------------------------------
      public:
        static BAC_CONNECT_MESSAGEPlugin^ get_instance();

        static void dispose();

      private:
        BAC_CONNECT_MESSAGEPlugin()
        : DefaultTypePlugin(
            "BAC_CONNECT_MESSAGE",

            false, // not keyed    
            false, // use RTPS-compliant alignment
            #ifndef NDDS_STANDALONE_TYPE
            BAC_CONNECT_MESSAGE::get_typecode()) {
            #else
            nullptr) {
                #endif
                // empty
            }

            static BAC_CONNECT_MESSAGEPlugin^ _singleton;
        };

        /* ------------------------------------------------------------------------
        * Enum Type: StationKind
        * ------------------------------------------------------------------------ */

        public ref class StationKindPlugin {
            // --- (De)Serialization Methods: --------------------------------------------
          public:
            System::Boolean serialize(
                TypePluginEndpointData^ endpoint_data,
                StationKind sample,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::Boolean deserialize_sample(
                TypePluginEndpointData^ endpoint_data,
                StationKind% sample,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_sample, 
                System::Object^ endpoint_plugin_qos);

            System::Boolean skip(
                TypePluginEndpointData^ endpoint_data,
                CdrStream% stream,
                System::Boolean skip_encapsulation,
                System::Boolean skip_sample, 
                System::Object^ endpoint_plugin_qos);

            System::UInt32 get_serialized_sample_max_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 size);

            System::UInt32 get_serialized_sample_min_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 size);

            System::UInt32 get_serialized_sample_size(
                TypePluginEndpointData^ endpoint_data,
                Boolean include_encapsulation,
                UInt16 encapsulation_id,
                UInt32 current_alignment,
                StationKind sample);

            // --- Key Management functions: ---------------------------------------------
          public:
            System::Boolean serialize_key(
                TypePluginEndpointData^ endpoint_data,
                StationKind key,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::Boolean serialize_key_for_keyhash(
                TypePluginEndpointData^ endpoint_data,
                StationKind key,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::Boolean deserialize_key_sample(
                TypePluginEndpointData^ endpoint_data,
                StationKind% key,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::UInt32 get_serialized_key_max_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 current_alignment);

            System::UInt32 get_serialized_key_for_keyhash_max_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 current_alignment);

            System::Boolean serialized_sample_to_key(
                TypePluginEndpointData^ endpoint_data,
                StationKind% sample,
                CdrStream% stream, 
                Boolean deserialize_encapsulation,  
                Boolean deserialize_key, 
                Object^ endpoint_plugin_qos);

            // --- Support functions: ----------------------------------------------------
          public:
            void print_data(
                StationKind sample,
                System::String^ desc,
                System::UInt32 indent_level);

            // ---  Plug-in lifecycle management methods: --------------------------------
          public:
            static StationKindPlugin^ get_instance();

            static void dispose();

          private:
            StationKindPlugin() { /*empty*/ }

            static StationKindPlugin^ _singleton;
        };        

        /* ------------------------------------------------------------------------
        * Enum Type: LotStatusKind
        * ------------------------------------------------------------------------ */

        public ref class LotStatusKindPlugin {
            // --- (De)Serialization Methods: --------------------------------------------
          public:
            System::Boolean serialize(
                TypePluginEndpointData^ endpoint_data,
                LotStatusKind sample,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::Boolean deserialize_sample(
                TypePluginEndpointData^ endpoint_data,
                LotStatusKind% sample,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_sample, 
                System::Object^ endpoint_plugin_qos);

            System::Boolean skip(
                TypePluginEndpointData^ endpoint_data,
                CdrStream% stream,
                System::Boolean skip_encapsulation,
                System::Boolean skip_sample, 
                System::Object^ endpoint_plugin_qos);

            System::UInt32 get_serialized_sample_max_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 size);

            System::UInt32 get_serialized_sample_min_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 size);

            System::UInt32 get_serialized_sample_size(
                TypePluginEndpointData^ endpoint_data,
                Boolean include_encapsulation,
                UInt16 encapsulation_id,
                UInt32 current_alignment,
                LotStatusKind sample);

            // --- Key Management functions: ---------------------------------------------
          public:
            System::Boolean serialize_key(
                TypePluginEndpointData^ endpoint_data,
                LotStatusKind key,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::Boolean serialize_key_for_keyhash(
                TypePluginEndpointData^ endpoint_data,
                LotStatusKind key,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::Boolean deserialize_key_sample(
                TypePluginEndpointData^ endpoint_data,
                LotStatusKind% key,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_sample,
                System::Object^ endpoint_plugin_qos);

            System::UInt32 get_serialized_key_max_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 current_alignment);

            System::UInt32 get_serialized_key_for_keyhash_max_size(
                TypePluginEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 current_alignment);

            System::Boolean serialized_sample_to_key(
                TypePluginEndpointData^ endpoint_data,
                LotStatusKind% sample,
                CdrStream% stream, 
                Boolean deserialize_encapsulation,  
                Boolean deserialize_key, 
                Object^ endpoint_plugin_qos);

            // --- Support functions: ----------------------------------------------------
          public:
            void print_data(
                LotStatusKind sample,
                System::String^ desc,
                System::UInt32 indent_level);

            // ---  Plug-in lifecycle management methods: --------------------------------
          public:
            static LotStatusKindPlugin^ get_instance();

            static void dispose();

          private:
            LotStatusKindPlugin() { /*empty*/ }

            static LotStatusKindPlugin^ _singleton;
        };        

        /* ------------------------------------------------------------------------
        * Type: ChocolateLotState
        * ------------------------------------------------------------------------ */

        public ref class ChocolateLotStatePlugin :
        DefaultTypePlugin<ChocolateLotState^> {
            // --- Support methods: ------------------------------------------------------
          public:
            void print_data(
                ChocolateLotState^ sample,
                System::String^ desc,
                System::UInt32 indent);

            // --- (De)Serialize methods: ------------------------------------------------
          public:
            virtual System::Boolean serialize(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ sample,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos) override;

            virtual System::Boolean deserialize_sample(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ sample,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_sample, 
                System::Object^ endpoint_plugin_qos) override;

            System::Boolean skip(
                TypePluginDefaultEndpointData^ endpoint_data,
                CdrStream% stream,
                System::Boolean skip_encapsulation,  
                System::Boolean skip_sample, 
                System::Object^ endpoint_plugin_qos);

            virtual System::UInt32 get_serialized_sample_max_size(
                TypePluginDefaultEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 size) override;

            virtual System::UInt32 get_serialized_sample_min_size(
                TypePluginDefaultEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 size) override;

            virtual System::UInt32 get_serialized_sample_size(
                TypePluginDefaultEndpointData^ endpoint_data,
                Boolean include_encapsulation,
                UInt16 encapsulation_id,
                UInt32 current_alignment,
                ChocolateLotState^ sample) override;

            // ---  Key Management functions: --------------------------------------------
          public:
            virtual System::UInt32 get_serialized_key_max_size(
                TypePluginDefaultEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 current_alignment) override;

            virtual System::UInt32 get_serialized_key_for_keyhash_max_size(
                TypePluginDefaultEndpointData^ endpoint_data,
                System::Boolean include_encapsulation,
                System::UInt16  encapsulation_id,
                System::UInt32 current_alignment) override;     

            virtual System::Boolean serialize_key(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ key,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos) override;

            virtual System::Boolean serialize_key_for_keyhash(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ key,
                CdrStream% stream,
                System::Boolean serialize_encapsulation,
                System::UInt16  encapsulation_id,
                System::Boolean serialize_sample,
                System::Object^ endpoint_plugin_qos) override;

            virtual System::Boolean deserialize_key_sample(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ key,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_sample,
                System::Object^ endpoint_plugin_qos) override;

            System::Boolean serialized_sample_to_key(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ sample,
                CdrStream% stream,
                System::Boolean deserialize_encapsulation,
                System::Boolean deserialize_key,
                System::Object^ endpoint_plugin_qos);

            virtual System::Boolean instance_to_key(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ key,
                ChocolateLotState^ instance) override;

            virtual System::Boolean key_to_instance(
                TypePluginDefaultEndpointData^ endpoint_data,
                ChocolateLotState^ instance,
                ChocolateLotState^ key) override;

            virtual System::Boolean serialized_sample_to_key_hash(
                TypePluginDefaultEndpointData^ endpoint_data,
                CdrStream% stream,
                KeyHash_t% key_hash,
                System::Boolean deserialize_encapsulation,
                System::Object^ endpoint_plugin_qos) override;

            // ---  Plug-in lifecycle management methods: --------------------------------
          public:
            static ChocolateLotStatePlugin^ get_instance();

            static void dispose();

          private:
            ChocolateLotStatePlugin()
            : DefaultTypePlugin(
                "ChocolateLotState",

                true, //keyed     
                false, // use RTPS-compliant alignment
                #ifndef NDDS_STANDALONE_TYPE
                ChocolateLotState::get_typecode()) {
                #else
                nullptr) {
                    #endif
                    // empty
                }

                static ChocolateLotStatePlugin^ _singleton;
            };


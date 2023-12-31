// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TestProject1/MyGameNetworkManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGameNetworkManager() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	TESTPROJECT1_API UClass* Z_Construct_UClass_AMyGameNetworkManager();
	TESTPROJECT1_API UClass* Z_Construct_UClass_AMyGameNetworkManager_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TestProject1();
// End Cross Module References
	DEFINE_FUNCTION(AMyGameNetworkManager::execCloseConnection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseConnection();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyGameNetworkManager::execSendData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_DataToSend);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SendData(Z_Param_DataToSend);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyGameNetworkManager::execConnectToServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ConnectToServer();
		P_NATIVE_END;
	}
	void AMyGameNetworkManager::StaticRegisterNativesAMyGameNetworkManager()
	{
		UClass* Class = AMyGameNetworkManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseConnection", &AMyGameNetworkManager::execCloseConnection },
			{ "ConnectToServer", &AMyGameNetworkManager::execConnectToServer },
			{ "SendData", &AMyGameNetworkManager::execSendData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection_Statics::Function_MetaDataParams[] = {
		{ "Category", "Network" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to close the connection\n" },
#endif
		{ "ModuleRelativePath", "MyGameNetworkManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to close the connection" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyGameNetworkManager, nullptr, "CloseConnection", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics
	{
		struct MyGameNetworkManager_eventConnectToServer_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyGameNetworkManager_eventConnectToServer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyGameNetworkManager_eventConnectToServer_Parms), &Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Network" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to connect to the server\n" },
#endif
		{ "ModuleRelativePath", "MyGameNetworkManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to connect to the server" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyGameNetworkManager, nullptr, "ConnectToServer", nullptr, nullptr, Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::MyGameNetworkManager_eventConnectToServer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::MyGameNetworkManager_eventConnectToServer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics
	{
		struct MyGameNetworkManager_eventSendData_Parms
		{
			FString DataToSend;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataToSend_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DataToSend;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::NewProp_DataToSend_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::NewProp_DataToSend = { "DataToSend", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyGameNetworkManager_eventSendData_Parms, DataToSend), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::NewProp_DataToSend_MetaData), Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::NewProp_DataToSend_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::NewProp_DataToSend,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Network" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to send data\n" },
#endif
		{ "ModuleRelativePath", "MyGameNetworkManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to send data" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyGameNetworkManager, nullptr, "SendData", nullptr, nullptr, Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::MyGameNetworkManager_eventSendData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::MyGameNetworkManager_eventSendData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMyGameNetworkManager_SendData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyGameNetworkManager_SendData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyGameNetworkManager);
	UClass* Z_Construct_UClass_AMyGameNetworkManager_NoRegister()
	{
		return AMyGameNetworkManager::StaticClass();
	}
	struct Z_Construct_UClass_AMyGameNetworkManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerIP_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ServerIP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerPort_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ServerPort;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyGameNetworkManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TestProject1,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyGameNetworkManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyGameNetworkManager_CloseConnection, "CloseConnection" }, // 3906743233
		{ &Z_Construct_UFunction_AMyGameNetworkManager_ConnectToServer, "ConnectToServer" }, // 4128305985
		{ &Z_Construct_UFunction_AMyGameNetworkManager_SendData, "SendData" }, // 1378778853
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyGameNetworkManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyGameNetworkManager.h" },
		{ "ModuleRelativePath", "MyGameNetworkManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerIP_MetaData[] = {
		{ "Category", "Network" },
		{ "ModuleRelativePath", "MyGameNetworkManager.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerIP = { "ServerIP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyGameNetworkManager, ServerIP), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerIP_MetaData), Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerIP_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerPort_MetaData[] = {
		{ "Category", "Network" },
		{ "ModuleRelativePath", "MyGameNetworkManager.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerPort = { "ServerPort", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyGameNetworkManager, ServerPort), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerPort_MetaData), Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerPort_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyGameNetworkManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerIP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyGameNetworkManager_Statics::NewProp_ServerPort,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyGameNetworkManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyGameNetworkManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyGameNetworkManager_Statics::ClassParams = {
		&AMyGameNetworkManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyGameNetworkManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyGameNetworkManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameNetworkManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AMyGameNetworkManager()
	{
		if (!Z_Registration_Info_UClass_AMyGameNetworkManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyGameNetworkManager.OuterSingleton, Z_Construct_UClass_AMyGameNetworkManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyGameNetworkManager.OuterSingleton;
	}
	template<> TESTPROJECT1_API UClass* StaticClass<AMyGameNetworkManager>()
	{
		return AMyGameNetworkManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyGameNetworkManager);
	struct Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyGameNetworkManager, AMyGameNetworkManager::StaticClass, TEXT("AMyGameNetworkManager"), &Z_Registration_Info_UClass_AMyGameNetworkManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyGameNetworkManager), 14901535U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_2719207120(TEXT("/Script/TestProject1"),
		Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

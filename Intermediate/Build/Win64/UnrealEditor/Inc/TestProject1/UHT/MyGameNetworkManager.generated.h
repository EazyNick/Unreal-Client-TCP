// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyGameNetworkManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TESTPROJECT1_MyGameNetworkManager_generated_h
#error "MyGameNetworkManager.generated.h already included, missing '#pragma once' in MyGameNetworkManager.h"
#endif
#define TESTPROJECT1_MyGameNetworkManager_generated_h

#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_SPARSE_DATA
#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCloseConnection); \
	DECLARE_FUNCTION(execSendData); \
	DECLARE_FUNCTION(execConnectToServer);


#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_ACCESSORS
#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyGameNetworkManager(); \
	friend struct Z_Construct_UClass_AMyGameNetworkManager_Statics; \
public: \
	DECLARE_CLASS(AMyGameNetworkManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TestProject1"), NO_API) \
	DECLARE_SERIALIZER(AMyGameNetworkManager)


#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameNetworkManager(AMyGameNetworkManager&&); \
	NO_API AMyGameNetworkManager(const AMyGameNetworkManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameNetworkManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameNetworkManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyGameNetworkManager)


#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_12_PROLOG
#define FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_SPARSE_DATA \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_ACCESSORS \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_INCLASS_NO_PURE_DECLS \
	FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TESTPROJECT1_API UClass* StaticClass<class AMyGameNetworkManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_TestProject1_Source_TestProject1_MyGameNetworkManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

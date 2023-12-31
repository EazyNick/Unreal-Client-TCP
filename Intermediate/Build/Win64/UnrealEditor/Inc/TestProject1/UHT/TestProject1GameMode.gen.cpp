// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TestProject1/TestProject1GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestProject1GameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	TESTPROJECT1_API UClass* Z_Construct_UClass_ATestProject1GameMode();
	TESTPROJECT1_API UClass* Z_Construct_UClass_ATestProject1GameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TestProject1();
// End Cross Module References
	void ATestProject1GameMode::StaticRegisterNativesATestProject1GameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATestProject1GameMode);
	UClass* Z_Construct_UClass_ATestProject1GameMode_NoRegister()
	{
		return ATestProject1GameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATestProject1GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestProject1GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TestProject1,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestProject1GameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestProject1GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TestProject1GameMode.h" },
		{ "ModuleRelativePath", "TestProject1GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestProject1GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestProject1GameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATestProject1GameMode_Statics::ClassParams = {
		&ATestProject1GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATestProject1GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATestProject1GameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ATestProject1GameMode()
	{
		if (!Z_Registration_Info_UClass_ATestProject1GameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATestProject1GameMode.OuterSingleton, Z_Construct_UClass_ATestProject1GameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATestProject1GameMode.OuterSingleton;
	}
	template<> TESTPROJECT1_API UClass* StaticClass<ATestProject1GameMode>()
	{
		return ATestProject1GameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestProject1GameMode);
	ATestProject1GameMode::~ATestProject1GameMode() {}
	struct Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_TestProject1GameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_TestProject1GameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATestProject1GameMode, ATestProject1GameMode::StaticClass, TEXT("ATestProject1GameMode"), &Z_Registration_Info_UClass_ATestProject1GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATestProject1GameMode), 874784009U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_TestProject1GameMode_h_3606588880(TEXT("/Script/TestProject1"),
		Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_TestProject1GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_TestProject1_Source_TestProject1_TestProject1GameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

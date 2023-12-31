// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestProject1_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TestProject1;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TestProject1()
	{
		if (!Z_Registration_Info_UPackage__Script_TestProject1.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TestProject1",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x7F954C82,
				0x9CEB775B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TestProject1.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TestProject1.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TestProject1(Z_Construct_UPackage__Script_TestProject1, TEXT("/Script/TestProject1"), Z_Registration_Info_UPackage__Script_TestProject1, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7F954C82, 0x9CEB775B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

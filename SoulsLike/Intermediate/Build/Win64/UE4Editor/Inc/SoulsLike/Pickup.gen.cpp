// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoulsLike/Pickup.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickup() {}
// Cross Module References
	SOULSLIKE_API UClass* Z_Construct_UClass_APickup_NoRegister();
	SOULSLIKE_API UClass* Z_Construct_UClass_APickup();
	SOULSLIKE_API UClass* Z_Construct_UClass_AItem();
	UPackage* Z_Construct_UPackage__Script_SoulsLike();
// End Cross Module References
	void APickup::StaticRegisterNativesAPickup()
	{
	}
	UClass* Z_Construct_UClass_APickup_NoRegister()
	{
		return APickup::StaticClass();
	}
	struct Z_Construct_UClass_APickup_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoulsCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_SoulsCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APickup_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItem,
		(UObject* (*)())Z_Construct_UPackage__Script_SoulsLike,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Pickup.h" },
		{ "ModuleRelativePath", "Pickup.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::NewProp_SoulsCount_MetaData[] = {
		{ "Category", "Souls Count" },
		{ "ModuleRelativePath", "Pickup.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_APickup_Statics::NewProp_SoulsCount = { "SoulsCount", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APickup, SoulsCount), METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::NewProp_SoulsCount_MetaData, ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::NewProp_SoulsCount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APickup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup_Statics::NewProp_SoulsCount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APickup_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickup>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APickup_Statics::ClassParams = {
		&APickup::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APickup_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APickup()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APickup_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APickup, 4057107531);
	template<> SOULSLIKE_API UClass* StaticClass<APickup>()
	{
		return APickup::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APickup(Z_Construct_UClass_APickup, &APickup::StaticClass, TEXT("/Script/SoulsLike"), TEXT("APickup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickup);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

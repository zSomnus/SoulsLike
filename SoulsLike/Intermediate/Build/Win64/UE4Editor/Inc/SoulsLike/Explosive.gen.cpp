// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoulsLike/Explosive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExplosive() {}
// Cross Module References
	SOULSLIKE_API UClass* Z_Construct_UClass_AExplosive_NoRegister();
	SOULSLIKE_API UClass* Z_Construct_UClass_AExplosive();
	SOULSLIKE_API UClass* Z_Construct_UClass_AItem();
	UPackage* Z_Construct_UPackage__Script_SoulsLike();
// End Cross Module References
	void AExplosive::StaticRegisterNativesAExplosive()
	{
	}
	UClass* Z_Construct_UClass_AExplosive_NoRegister()
	{
		return AExplosive::StaticClass();
	}
	struct Z_Construct_UClass_AExplosive_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Damage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AExplosive_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItem,
		(UObject* (*)())Z_Construct_UPackage__Script_SoulsLike,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExplosive_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Explosive.h" },
		{ "ModuleRelativePath", "Explosive.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExplosive_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Explosive.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AExplosive_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AExplosive, Damage), METADATA_PARAMS(Z_Construct_UClass_AExplosive_Statics::NewProp_Damage_MetaData, ARRAY_COUNT(Z_Construct_UClass_AExplosive_Statics::NewProp_Damage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AExplosive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExplosive_Statics::NewProp_Damage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AExplosive_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AExplosive>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AExplosive_Statics::ClassParams = {
		&AExplosive::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AExplosive_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AExplosive_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AExplosive_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AExplosive_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AExplosive()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AExplosive_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AExplosive, 3214773652);
	template<> SOULSLIKE_API UClass* StaticClass<AExplosive>()
	{
		return AExplosive::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AExplosive(Z_Construct_UClass_AExplosive, &AExplosive::StaticClass, TEXT("/Script/SoulsLike"), TEXT("AExplosive"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AExplosive);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
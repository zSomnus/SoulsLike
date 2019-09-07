// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoulsLike/SoulsLikeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoulsLikeGameModeBase() {}
// Cross Module References
	SOULSLIKE_API UClass* Z_Construct_UClass_ASoulsLikeGameModeBase_NoRegister();
	SOULSLIKE_API UClass* Z_Construct_UClass_ASoulsLikeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_SoulsLike();
// End Cross Module References
	void ASoulsLikeGameModeBase::StaticRegisterNativesASoulsLikeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ASoulsLikeGameModeBase_NoRegister()
	{
		return ASoulsLikeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ASoulsLikeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SoulsLike,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SoulsLikeGameModeBase.h" },
		{ "ModuleRelativePath", "SoulsLikeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoulsLikeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::ClassParams = {
		&ASoulsLikeGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoulsLikeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASoulsLikeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASoulsLikeGameModeBase, 1913727079);
	template<> SOULSLIKE_API UClass* StaticClass<ASoulsLikeGameModeBase>()
	{
		return ASoulsLikeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASoulsLikeGameModeBase(Z_Construct_UClass_ASoulsLikeGameModeBase, &ASoulsLikeGameModeBase::StaticClass, TEXT("/Script/SoulsLike"), TEXT("ASoulsLikeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoulsLikeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

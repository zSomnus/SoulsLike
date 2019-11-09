// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOULSLIKE_Explosive_generated_h
#error "Explosive.generated.h already included, missing '#pragma once' in Explosive.h"
#endif
#define SOULSLIKE_Explosive_generated_h

#define SoulsLike_Source_SoulsLike_Explosive_h_15_RPC_WRAPPERS
#define SoulsLike_Source_SoulsLike_Explosive_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define SoulsLike_Source_SoulsLike_Explosive_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAExplosive(); \
	friend struct Z_Construct_UClass_AExplosive_Statics; \
public: \
	DECLARE_CLASS(AExplosive, AItem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AExplosive)


#define SoulsLike_Source_SoulsLike_Explosive_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAExplosive(); \
	friend struct Z_Construct_UClass_AExplosive_Statics; \
public: \
	DECLARE_CLASS(AExplosive, AItem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AExplosive)


#define SoulsLike_Source_SoulsLike_Explosive_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AExplosive(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AExplosive) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AExplosive); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AExplosive); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AExplosive(AExplosive&&); \
	NO_API AExplosive(const AExplosive&); \
public:


#define SoulsLike_Source_SoulsLike_Explosive_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AExplosive(AExplosive&&); \
	NO_API AExplosive(const AExplosive&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AExplosive); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AExplosive); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AExplosive)


#define SoulsLike_Source_SoulsLike_Explosive_h_15_PRIVATE_PROPERTY_OFFSET
#define SoulsLike_Source_SoulsLike_Explosive_h_12_PROLOG
#define SoulsLike_Source_SoulsLike_Explosive_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_Explosive_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_Explosive_h_15_RPC_WRAPPERS \
	SoulsLike_Source_SoulsLike_Explosive_h_15_INCLASS \
	SoulsLike_Source_SoulsLike_Explosive_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SoulsLike_Source_SoulsLike_Explosive_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_Explosive_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_Explosive_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_Explosive_h_15_INCLASS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_Explosive_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOULSLIKE_API UClass* StaticClass<class AExplosive>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SoulsLike_Source_SoulsLike_Explosive_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

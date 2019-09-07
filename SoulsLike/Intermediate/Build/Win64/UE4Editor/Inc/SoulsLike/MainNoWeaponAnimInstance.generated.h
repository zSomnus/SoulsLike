// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOULSLIKE_MainNoWeaponAnimInstance_generated_h
#error "MainNoWeaponAnimInstance.generated.h already included, missing '#pragma once' in MainNoWeaponAnimInstance.h"
#endif
#define SOULSLIKE_MainNoWeaponAnimInstance_generated_h

#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateAnimationProperties) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateAnimationProperties(); \
		P_NATIVE_END; \
	}


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateAnimationProperties) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateAnimationProperties(); \
		P_NATIVE_END; \
	}


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMainNoWeaponAnimInstance(); \
	friend struct Z_Construct_UClass_UMainNoWeaponAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMainNoWeaponAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(UMainNoWeaponAnimInstance)


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUMainNoWeaponAnimInstance(); \
	friend struct Z_Construct_UClass_UMainNoWeaponAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMainNoWeaponAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(UMainNoWeaponAnimInstance)


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMainNoWeaponAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainNoWeaponAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainNoWeaponAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainNoWeaponAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMainNoWeaponAnimInstance(UMainNoWeaponAnimInstance&&); \
	NO_API UMainNoWeaponAnimInstance(const UMainNoWeaponAnimInstance&); \
public:


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMainNoWeaponAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMainNoWeaponAnimInstance(UMainNoWeaponAnimInstance&&); \
	NO_API UMainNoWeaponAnimInstance(const UMainNoWeaponAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainNoWeaponAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainNoWeaponAnimInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainNoWeaponAnimInstance)


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET
#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_12_PROLOG
#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_RPC_WRAPPERS \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_INCLASS \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOULSLIKE_API UClass* StaticClass<class UMainNoWeaponAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SoulsLike_Source_SoulsLike_MainNoWeaponAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

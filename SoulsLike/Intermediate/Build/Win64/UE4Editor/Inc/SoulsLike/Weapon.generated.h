// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOULSLIKE_Weapon_generated_h
#error "Weapon.generated.h already included, missing '#pragma once' in Weapon.h"
#endif
#define SOULSLIKE_Weapon_generated_h

#define SoulsLike_Source_SoulsLike_Weapon_h_15_RPC_WRAPPERS
#define SoulsLike_Source_SoulsLike_Weapon_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define SoulsLike_Source_SoulsLike_Weapon_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWeapon(); \
	friend struct Z_Construct_UClass_AWeapon_Statics; \
public: \
	DECLARE_CLASS(AWeapon, AItem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AWeapon)


#define SoulsLike_Source_SoulsLike_Weapon_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAWeapon(); \
	friend struct Z_Construct_UClass_AWeapon_Statics; \
public: \
	DECLARE_CLASS(AWeapon, AItem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AWeapon)


#define SoulsLike_Source_SoulsLike_Weapon_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWeapon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeapon(AWeapon&&); \
	NO_API AWeapon(const AWeapon&); \
public:


#define SoulsLike_Source_SoulsLike_Weapon_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeapon(AWeapon&&); \
	NO_API AWeapon(const AWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWeapon)


#define SoulsLike_Source_SoulsLike_Weapon_h_15_PRIVATE_PROPERTY_OFFSET
#define SoulsLike_Source_SoulsLike_Weapon_h_12_PROLOG
#define SoulsLike_Source_SoulsLike_Weapon_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_Weapon_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_Weapon_h_15_RPC_WRAPPERS \
	SoulsLike_Source_SoulsLike_Weapon_h_15_INCLASS \
	SoulsLike_Source_SoulsLike_Weapon_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SoulsLike_Source_SoulsLike_Weapon_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_Weapon_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_Weapon_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_Weapon_h_15_INCLASS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_Weapon_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOULSLIKE_API UClass* StaticClass<class AWeapon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SoulsLike_Source_SoulsLike_Weapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOULSLIKE_MainPlayerController_generated_h
#error "MainPlayerController.generated.h already included, missing '#pragma once' in MainPlayerController.h"
#endif
#define SOULSLIKE_MainPlayerController_generated_h

#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_RPC_WRAPPERS
#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainPlayerController(); \
	friend struct Z_Construct_UClass_AMainPlayerController_Statics; \
public: \
	DECLARE_CLASS(AMainPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AMainPlayerController)


#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMainPlayerController(); \
	friend struct Z_Construct_UClass_AMainPlayerController_Statics; \
public: \
	DECLARE_CLASS(AMainPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AMainPlayerController)


#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainPlayerController(AMainPlayerController&&); \
	NO_API AMainPlayerController(const AMainPlayerController&); \
public:


#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainPlayerController(AMainPlayerController&&); \
	NO_API AMainPlayerController(const AMainPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainPlayerController)


#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_PRIVATE_PROPERTY_OFFSET
#define SoulsLike_Source_SoulsLike_MainPlayerController_h_12_PROLOG
#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_RPC_WRAPPERS \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_INCLASS \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SoulsLike_Source_SoulsLike_MainPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_MainPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOULSLIKE_API UClass* StaticClass<class AMainPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SoulsLike_Source_SoulsLike_MainPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

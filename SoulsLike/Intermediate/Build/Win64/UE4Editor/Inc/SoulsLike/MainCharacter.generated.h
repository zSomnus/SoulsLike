// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOULSLIKE_MainCharacter_generated_h
#error "MainCharacter.generated.h already included, missing '#pragma once' in MainCharacter.h"
#endif
#define SOULSLIKE_MainCharacter_generated_h

#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAttackStep) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackStep(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParry) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Parry(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Attack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDodge) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Dodge(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRoll) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Roll(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayAttackStepTimeline) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayAttackStepTimeline(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttackStepTimelineFinishedCallback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackStepTimelineFinishedCallback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttackStepTimelineCallback) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackStepTimelineCallback(Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayDodgeTimeline) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayDodgeTimeline(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDodgeTimelineFinishedCallback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DodgeTimelineFinishedCallback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDodgeTimelineCallback) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DodgeTimelineCallback(Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayRollTimeline) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayRollTimeline(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRollTimelineFinishedCallback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RollTimelineFinishedCallback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRollTimelineCallback) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RollTimelineCallback(Z_Param_value); \
		P_NATIVE_END; \
	}


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAttackStep) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackStep(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execParry) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Parry(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Attack(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDodge) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Dodge(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRoll) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Roll(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayAttackStepTimeline) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayAttackStepTimeline(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttackStepTimelineFinishedCallback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackStepTimelineFinishedCallback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttackStepTimelineCallback) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AttackStepTimelineCallback(Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayDodgeTimeline) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayDodgeTimeline(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDodgeTimelineFinishedCallback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DodgeTimelineFinishedCallback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDodgeTimelineCallback) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DodgeTimelineCallback(Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayRollTimeline) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayRollTimeline(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRollTimelineFinishedCallback) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RollTimelineFinishedCallback(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRollTimelineCallback) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RollTimelineCallback(Z_Param_value); \
		P_NATIVE_END; \
	}


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainCharacter(); \
	friend struct Z_Construct_UClass_AMainCharacter_Statics; \
public: \
	DECLARE_CLASS(AMainCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AMainCharacter)


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAMainCharacter(); \
	friend struct Z_Construct_UClass_AMainCharacter_Statics; \
public: \
	DECLARE_CLASS(AMainCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SoulsLike"), NO_API) \
	DECLARE_SERIALIZER(AMainCharacter)


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainCharacter(AMainCharacter&&); \
	NO_API AMainCharacter(const AMainCharacter&); \
public:


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainCharacter(AMainCharacter&&); \
	NO_API AMainCharacter(const AMainCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainCharacter)


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RollTimeline() { return STRUCT_OFFSET(AMainCharacter, RollTimeline); } \
	FORCEINLINE static uint32 __PPO__DodgeTimeline() { return STRUCT_OFFSET(AMainCharacter, DodgeTimeline); } \
	FORCEINLINE static uint32 __PPO__AttackStepTimeline() { return STRUCT_OFFSET(AMainCharacter, AttackStepTimeline); } \
	FORCEINLINE static uint32 __PPO__RollFloatCurve() { return STRUCT_OFFSET(AMainCharacter, RollFloatCurve); } \
	FORCEINLINE static uint32 __PPO__DodgeFloatCurve() { return STRUCT_OFFSET(AMainCharacter, DodgeFloatCurve); } \
	FORCEINLINE static uint32 __PPO__AttackStepFloatCurve() { return STRUCT_OFFSET(AMainCharacter, AttackStepFloatCurve); } \
	FORCEINLINE static uint32 __PPO__TimelineDirection() { return STRUCT_OFFSET(AMainCharacter, TimelineDirection); }


#define SoulsLike_Source_SoulsLike_MainCharacter_h_18_PROLOG
#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_RPC_WRAPPERS \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_INCLASS \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SoulsLike_Source_SoulsLike_MainCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_INCLASS_NO_PURE_DECLS \
	SoulsLike_Source_SoulsLike_MainCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOULSLIKE_API UClass* StaticClass<class AMainCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SoulsLike_Source_SoulsLike_MainCharacter_h


#define FOREACH_ENUM_EMOVEMENTSTATUS(op) \
	op(EMovementStatus::EMS_Normal) \
	op(EMovementStatus::EMS_Dashing) 

enum class EMovementStatus : uint8;
template<> SOULSLIKE_API UEnum* StaticEnum<EMovementStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

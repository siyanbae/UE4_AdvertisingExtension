// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AdvertisingExtensionCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FResultRewardedAdDynamicDelegate, const bool, IsSuccess, const FString&, RewardType, const int32, Amount);
DECLARE_DELEGATE_ThreeParams(FResultRewardedAdDelegate,const bool /*IsSuccess*/, const FString& /*RewardType*/, const int32 /*Amount*/);
/**
 * 
 */
UCLASS()
class ADVERTISINGEXTENSION_API UAdvertisingExtensionCallback : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable, Category = "Utilities|Platform")
	FResultRewardedAdDynamicDelegate OnResultRewardedAdDynamicDelegate;

	FResultRewardedAdDelegate OnResultRewardedAdDelegate;

	static UAdvertisingExtensionCallback* GetInstance();
};

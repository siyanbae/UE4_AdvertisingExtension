// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdvertisingExtensionBPLibrary.generated.h"

class UAdvertisingExtensionCallback;

UCLASS()
class UAdvertisingExtensionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	/** try to acquire permissions and return a singleton callback proxy object containing OnPermissionsGranted delegate */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Advertising Rewarded Callback"), Category = "Utilities|Platform")
	static UAdvertisingExtensionCallback* GetAdvertisingCallback();

	UFUNCTION(BlueprintCallable, Category = "Utilities|Platform")
	static void LoadRewardedVideoAd(const int32 adID, const bool isShowAutomatically);
		
	UFUNCTION(BlueprintCallable, Category = "Utilities|Platform")
	static void ShowRewardedVideoAd();

	UFUNCTION(BlueprintPure, Category = "Utilities|Platform")
	static bool IsRewardedVideoAdAvailable();

	UFUNCTION(BlueprintPure, Category = "Utilities|Platform")
	static bool IsRewardedVideoAdRequested();
};

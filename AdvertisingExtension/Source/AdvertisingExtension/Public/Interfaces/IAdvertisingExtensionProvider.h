// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

/** Generic interface for an advertising provider. Other modules can define more and register them with this module. */
class IAdvertisingExtensionProvider
{
public:
	virtual ~IAdvertisingExtensionProvider() = default;
	virtual void LoadRewardedVideoAd(const int32 adID, const bool isShowAutomatically) = 0;
	virtual bool IsRewardedVideoAdAvailable() = 0;
	virtual bool IsRewardedVideoAdRequested() = 0;
	virtual void ShowRewardedVideoAd() = 0;
};
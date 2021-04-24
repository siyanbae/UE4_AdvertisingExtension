// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IAdvertisingExtensionProvider.h"
/**
 * 
 */
class FAndroidAdvertisingExtension : public IAdvertisingExtensionProvider
{
public:
	virtual void LoadRewardedVideoAd(const int32 adID, const bool isShowAutomatically) override;
	virtual bool IsRewardedVideoAdAvailable() override;
	virtual bool IsRewardedVideoAdRequested() override;
	virtual void ShowRewardedVideoAd() override;
};

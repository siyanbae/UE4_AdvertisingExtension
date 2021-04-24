// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvertisingExtensionBPLibrary.h"
#include "AdvertisingExtension.h"
#include "AdvertisingExtensionCallback.h"

UAdvertisingExtensionBPLibrary::UAdvertisingExtensionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

UAdvertisingExtensionCallback* UAdvertisingExtensionBPLibrary::GetAdvertisingCallback()
{
	return UAdvertisingExtensionCallback::GetInstance();
}

void UAdvertisingExtensionBPLibrary::LoadRewardedVideoAd(const int32 adID, const bool isShowAutomatically)
{
	if (FAdvertisingProviderPtr Provider = FAdvertisingExtension::Get().GetAdvertisingProvider())
	{
		Provider->LoadRewardedVideoAd(adID, isShowAutomatically);
	}
}

void UAdvertisingExtensionBPLibrary::ShowRewardedVideoAd()
{
	if (FAdvertisingProviderPtr Provider = FAdvertisingExtension::Get().GetAdvertisingProvider())
	{
		Provider->ShowRewardedVideoAd();
	}
}

bool UAdvertisingExtensionBPLibrary::IsRewardedVideoAdAvailable()
{
	bool bResult = false;
	if (FAdvertisingProviderPtr Provider = FAdvertisingExtension::Get().GetAdvertisingProvider())
	{
		bResult = Provider->IsRewardedVideoAdAvailable();
	}
	return bResult;
}

bool UAdvertisingExtensionBPLibrary::IsRewardedVideoAdRequested()
{
	bool bResult = false;
	if (FAdvertisingProviderPtr Provider = FAdvertisingExtension::Get().GetAdvertisingProvider())
	{
		bResult = Provider->IsRewardedVideoAdRequested();
	}
	return bResult;
}


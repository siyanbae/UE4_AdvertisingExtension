// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvertisingExtension.h"
#include "AdvertisingExtensionCallback.h"
#if PLATFORM_ANDROID
#include "Android/AndroidAdvertisingExtension.h"
#endif

IMPLEMENT_MODULE(FAdvertisingExtension, AdvertisingExtension)
DEFINE_LOG_CATEGORY_STATIC( LogAdvertisingExtension, Display, All );

void FAdvertisingExtension::StartupModule()
{
	UAdvertisingExtensionCallback::GetInstance();

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if PLATFORM_ANDROID
	ProviderPtr = MakeShareable(new FAndroidAdvertisingExtension());
#endif
}

void FAdvertisingExtension::ShutdownModule()
{
#if PLATFORM_ANDROID
	ProviderPtr = nullptr;
#endif
}
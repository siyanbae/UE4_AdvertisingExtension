// Fill out your copyright notice in the Description page of Project Settings.


#include "Android/AndroidAdvertisingExtension.h"
#include "Modules/ModuleManager.h"
#include "Misc/ConfigCacheIni.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

void FAndroidAdvertisingExtension::LoadRewardedVideoAd(const int32 adID, const bool isShowAutomatically)
{
#if PLATFORM_ANDROID
	TArray<FString> AdUnitIDs;
	int32 count = GConfig->GetArray(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("AdMobAdUnitIDs"), AdUnitIDs, GEngineIni);

	FString AdUnitID;
	if (count == 0)
	{
		// Fall back to checking old setting
		bool found = GConfig->GetString(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("AdMobAdUnitID"), AdUnitID, GEngineIni);
	}

	if (adID >= 0 && adID < count && !AdUnitIDs[adID].IsEmpty())
	{
		AdUnitID = AdUnitIDs[adID];
	}

	if (!AdUnitID.IsEmpty())
	{
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			jmethodID AndroidThunkJava_LoadRewardedVideoAd =
				FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_LoadRewardedVideoAd", "(Ljava/lang/String;Z)V", false);

			auto AdUnitIDArg = FJavaHelper::ToJavaString(Env, AdUnitID);
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_LoadRewardedVideoAd, *AdUnitIDArg, isShowAutomatically);
		}
	}
#endif
}

bool FAndroidAdvertisingExtension::IsRewardedVideoAdAvailable()
{
#if PLATFORM_ANDROID
	bool bIsAdAvailable = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto bIsOptional = true;
		jmethodID AndroidThunkJava_IsRewardedVideoAdAvailable = FJavaWrapper::FindMethod(Env, FJavaWrapper::GoogleServicesClassID, "AndroidThunkJava_IsRewardedVideoAdAvailable", "()Z", bIsOptional);
		// call the java side
		bIsAdAvailable = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_IsRewardedVideoAdAvailable);
	}

	return bIsAdAvailable;
#else 
	return false;
#endif
}

bool FAndroidAdvertisingExtension::IsRewardedVideoAdRequested()
{
#if PLATFORM_ANDROID
	bool bIsAdAvailable = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto bIsOptional = true;
		jmethodID AndroidThunkJava_IsRewardedVideoAdRequested = FJavaWrapper::FindMethod(Env, FJavaWrapper::GoogleServicesClassID, "AndroidThunkJava_IsRewardedVideoAdRequested", "()Z", bIsOptional);
		// call the java side
		bIsAdAvailable = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_IsRewardedVideoAdRequested);
	}

	return bIsAdAvailable;
#else 
	return false;
#endif
}

void FAndroidAdvertisingExtension::ShowRewardedVideoAd()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto bIsOptional = true;
		jmethodID AndroidThunkJava_ShowRewardedVideoAd =
			FJavaWrapper::FindMethod(Env, FJavaWrapper::GoogleServicesClassID, "AndroidThunkJava_ShowRewardedVideoAd", "()V", bIsOptional);
		// call the java side
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_ShowRewardedVideoAd);
	}
#endif
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvertisingExtensionCallback.h"
#include "AdvertisingExtension.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

static UAdvertisingExtensionCallback *pProxy = nullptr;

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnResultAdmobRewardedAd(JNIEnv* jenv, jobject thiz, jboolean bSuccess, jstring jRewardType, jint iAmount)
{
	bool isSuccess = bSuccess == JNI_TRUE ? true : false;
	int32 Amount = iAmount;
	FString RewardType = FJavaHelper::FStringFromParam(jenv, jRewardType);

	UE_LOG(LogAdvertisingExtension, Log, TEXT("@@@@@@@@@@@@@@ nativeAdmobRewardedAd"));

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]() {
		pProxy->OnResultRewardedAdDelegate.ExecuteIfBound(isSuccess, RewardType, Amount);
		pProxy->OnResultRewardedAdDynamicDelegate.Broadcast(isSuccess, RewardType, Amount);
	}), TStatId(), nullptr, ENamedThreads::GameThread);
}
#endif

UAdvertisingExtensionCallback* UAdvertisingExtensionCallback::GetInstance()
{
	if (!pProxy) {
		pProxy = NewObject<UAdvertisingExtensionCallback>();
		pProxy->AddToRoot();

	}
	UE_LOG(LogAdvertisingExtension, Log, TEXT("UAdvertisingExtensionCallback::GetInstance"));
	return pProxy;
}

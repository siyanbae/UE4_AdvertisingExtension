// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "Interfaces/IAdvertisingExtensionProvider.h"

typedef TSharedPtr<IAdvertisingExtensionProvider, ESPMode::ThreadSafe> FAdvertisingProviderPtr;

class FAdvertisingExtension : public IModuleInterface
{
public:
	static inline FAdvertisingExtension& Get()
	{
		return FModuleManager::LoadModuleChecked< FAdvertisingExtension >( "AdvertisingExtension" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "AdvertisingExtension" );
	}

	FAdvertisingProviderPtr GetAdvertisingProvider()
	{
		return ProviderPtr;
	}

private:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	FAdvertisingProviderPtr ProviderPtr;
};
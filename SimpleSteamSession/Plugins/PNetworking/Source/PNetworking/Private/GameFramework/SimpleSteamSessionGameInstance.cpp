// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/SimpleSteamSessionGameInstance.h"

void USimpleSteamSessionGameInstance::Init()
{
	UniqueSteamSessionInstance = UPNetworkingInstanceSteam::GetUniqueInstance();
}

UPNetworkingInstanceSteam* USimpleSteamSessionGameInstance::GetUniqueSteamSessionInstance(const bool bTryRetrieveAgainFromPlugin)
{
	if (bTryRetrieveAgainFromPlugin)
	{
		UniqueSteamSessionInstance = UPNetworkingInstanceSteam::GetUniqueInstance();
	}

	if (!UniqueSteamSessionInstance)
	{
		UE_LOG(LogSteamNetworkingPlugin, Error, TEXT("GetUniqueSteamSessionInstance: Pointer to UniqueSteamInstance is invalid!"));	
		return nullptr;
	}

	return UniqueSteamSessionInstance;
}

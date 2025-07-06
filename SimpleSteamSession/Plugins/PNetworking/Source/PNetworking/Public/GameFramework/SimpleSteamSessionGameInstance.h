// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../PNetworkingInstanceSteam.h"
#include "../PNetworking.h"
#include "SimpleSteamSessionGameInstance.generated.h"


UCLASS()
class PNETWORKING_API USimpleSteamSessionGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	UPNetworkingInstanceSteam* UniqueSteamSessionInstance;

public:
	void Init() override;

	/// <summary>
	/// Retrieve UniqueInstance pointer of steam manager.
	/// </summary>
	/// <param name="bTryRetrieveAgainFromPlugin"> Try again to request UniqueInstance from the plugin. </param>
	/// <returns> Pointer to UniqueInstance. </returns>
	UFUNCTION(BlueprintCallable, Category = "SimpleSteamSession")
	UPNetworkingInstanceSteam* GetUniqueSteamSessionInstance(const bool bTryRetrieveAgainFromPlugin = false);
	
};

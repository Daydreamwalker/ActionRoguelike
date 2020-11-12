// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "SGameModeBase.generated.h"

class UEnvQuery;
class UEnvQueryInstanceBlueprintWrapper;
class UCurveFloat;
class ASCharacter;
class USSaveGame;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

	FString SlotName;

	UPROPERTY()
	USSaveGame* CurrentSaveGame;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TSubclassOf<AActor> MinionClass;

	FTimerHandle TimerHandle_SpawnTimer;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float SpawnTimerInterval;


	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	int KillCredits;

	UFUNCTION()
	void SpawnBotTimerElapsed();

	UFUNCTION()
	bool CanSpawnNewBot();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UEnvQuery* SpawnBotQuery;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UCurveFloat* DifficultyCurve;

	UFUNCTION()
	void OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);

	void RespawnPlayer(ASCharacter* Player);

	void UpdateGamePlayers(ASCharacter* Player);

	UFUNCTION()
	void RespawnPlayerElapsed(AController* Controller);

	void GivePlayerKillCredits(ASCharacter* Player);

public:

	virtual void OnActorKilled(AActor* VictimActor, AActor* Killer);

	ASGameModeBase();

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void StartPlay() override;

	void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	UFUNCTION(Exec)
	void KillAllAI();

	UFUNCTION(BlueprintCallable, Category = "Save")
	void WriteSaveGame();

	void LoadSaveGame();

	UPROPERTY(BlueprintReadOnly)
	float NumberOfAlivePlayers;
};

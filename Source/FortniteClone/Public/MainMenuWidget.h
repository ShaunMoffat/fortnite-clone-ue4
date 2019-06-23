// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UserWidget.h"
#include "MainMenuWidget.generated.h"

class UUserWidget;
class UTextReaderComponent;
class UGameLiftClientObject;
class UButton;

// This class does not need to be modified.
UCLASS(BlueprintType, Blueprintable)
class UMainMenuWidget : public UUserWidget
{
	GENERATED_UCLASS_BODY()

public:

	/** FText value displayed by this widget */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText Code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reader")
	UTextReaderComponent* TextReader;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Buttons")
	UButton* JoinGameButton;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift")
	FString AccessKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift")
	FString SecretKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift")
	FString QueueName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift")
	UGameLiftClientObject* Client;

	UFUNCTION(Category = "GameLift")
	void JoinGame();

	UFUNCTION(Category = "GameLift")
	void DescribeGameSessionQueues(const FString& QueueNameInput);

	UFUNCTION(Category = "GameLift")
	void OnDescribeGameSessionQueuesSuccess(const TArray<FString>& FleetARNs);

	UFUNCTION(Category = "GameLift")
	void OnDescribeGameSessionQueuesFailed(const FString& ErrorMessage);

	UFUNCTION(Category = "GameLift")
	void SearchGameSessions(const FString& FleetId);

	UFUNCTION(Category = "GameLift")
	void OnSearchGameSessionsSuccess(const TArray<FString>& GameSessionIds);

	UFUNCTION(Category = "GameLift")
	void OnSearchGameSessionsFailed(const FString& ErrorMessage);

	UFUNCTION(Category = "GameLift")
	void CreatePlayerSession(const FString& GameSessionId, const FString& PlayerSessionId);

	UFUNCTION(Category = "GameLift")
	void OnCreatePlayerSessionSuccess(const FString& IPAddress, const FString& Port, const FString& PlayerSessionID, const int& PlayerSessionStatus);

	UFUNCTION(Category = "GameLift")
	void OnCreatePlayerSessionFailed(const FString& ErrorMessage);

	UFUNCTION(Category = "GameLift")
	void StartGameSessionPlacement(const FString& QueueNameInput, const int& MaxPlayerCount, const FString& PlacementId);

	UFUNCTION(Category = "GameLift")
	void OnStartGameSessionPlacementSuccess(const FString& GameSessionId);

	UFUNCTION(Category = "GameLift")
	void OnStartGameSessionPlacementFailed(const FString& ErrorMessage);

private:
	bool SearchGameSessionsFinished;

	bool CreatePlayerSessionFinished;

	bool DescribeGameSessionQueuesFinished;

	bool StartGameSessionPlacementFinished;

	UButton* JoinGameButton;

	FString GenerateRandomId();

	virtual void NativeConstruct() override;

};


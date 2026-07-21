// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TWINSTICKSHOOTER_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorPool();

	UPROPERTY(EditAnywhere)
	int defaultSize = 10; // tamaño inicial del pool

	UPROPERTY(EditAnywhere)
	TArray<AActor*> actorPool; //lista de actores a llamar

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> actorTemplate; //la clase del actor del pool


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// función que instancea los actores;
	AActor* InstancePoolActor(TSubclassOf<AActor> actorReference);
	AActor* FindFirstAvailableActor();


public:	
	
	//Obtener un actor del Pool
	UFUNCTION(BlueprintCallable)
	AActor* GetActorFromPool();

		
};

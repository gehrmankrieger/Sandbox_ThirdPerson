// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthPickup.generated.h"

UCLASS()
class SANDBOX_THIRDPERSON_API AHealthPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	AHealthPickup();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pickup")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Pickup")
	TObjectPtr<class USphereComponent> Sphere;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnPickedUp(AActor* Collector);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "0"))
	float HealAmount = 25.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pickup")
	int32 MaxUses = 3;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Pickup")
	int32 UsesLeft = 0;

	UFUNCTION(BlueprintPure, Category="Pickup")
	bool HasUsesLeft() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnPickupReady();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pickup")
	bool CanBePickedUp() const;

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void LogHealAmount() const;

public:	
	virtual void Tick(float DeltaTime) override;

};

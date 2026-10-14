// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DrillsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOX_THIRDPERSON_API UDrillsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Drills")
	static bool IsEven(int32 Number);

	UFUNCTION(BlueprintPure, Category = "Drills")
	static float Clamp01(float Value);

	UFUNCTION(BlueprintPure, Category = "Drills")
	static void GetMinMax(int32 A, int32 B, int32& OutMin, int32& OutMax);
	
};

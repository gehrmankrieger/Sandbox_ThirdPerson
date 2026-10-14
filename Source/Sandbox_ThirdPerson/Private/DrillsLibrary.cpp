// Fill out your copyright notice in the Description page of Project Settings.


#include "DrillsLibrary.h"

bool UDrillsLibrary::IsEven(int32 Number)
{
	return Number % 2 == 0;
}

float UDrillsLibrary::Clamp01(float Value)
{
	if (Value < 0.f) return 0.f;
	if (Value > 1.f) return 1.f;
	return Value;
}

void UDrillsLibrary::GetMinMax(int32 A, int32 B, int32& OutMin, int32& OutMax)
{
	OutMin = FMath::Min(A, B);
	OutMax = FMath::Max(A, B);
}
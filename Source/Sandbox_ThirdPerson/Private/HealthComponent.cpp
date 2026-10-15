

#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health, MaxHealth);
	
}

void UHealthComponent::TakeHit(float Amount)
{
	ApplyHealthChange(-Amount);
}

void UHealthComponent::Heal(float Amount)
{
	ApplyHealthChange(Amount);
}

void UHealthComponent::ApplyHealthChange(float Delta)
{
	const float OldHealth = Health;

	Health = FMath::Clamp(Health + Delta, 0.f, MaxHealth);

	if (Health == OldHealth)
	{
		return;
	}

	OnHealthChanged.Broadcast(Health, MaxHealth);
	if (Health <= 0.f && OldHealth > 0.f)
	{
		OnDeath.Broadcast();
	}

}


#include "HealthPickup.h"

AHealthPickup::AHealthPickup()
{

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	PrimaryActorTick.bCanEverTick = false;

}

void AHealthPickup::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("HealthPickup %s is ready"), *GetName());
	Super::BeginPlay();

	UsesLeft = MaxUses;  
	OnPickupReady();
	
}

bool AHealthPickup::HasUsesLeft() const
{
	return UsesLeft > 0;
}

bool AHealthPickup::CanBePickedUp_Implementation() const
{
	return HasUsesLeft();
}

void AHealthPickup::LogHealAmount() const
{
	UE_LOG(LogTemp, Warning, TEXT("Heals for %.1f"), HealAmount);
}

void AHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


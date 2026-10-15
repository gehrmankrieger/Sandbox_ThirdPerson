

#include "HealthPickup.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "HealthComponent.h"

AHealthPickup::AHealthPickup()
{

	PrimaryActorTick.bCanEverTick = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SPHERE"));
	Sphere->SetSphereRadius(60.f);
	Sphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Sphere->SetGenerateOverlapEvents(true);
	SetRootComponent(Sphere);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void AHealthPickup::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("HealthPickup %s is ready"), *GetName());
	Super::BeginPlay();

	UsesLeft = MaxUses;  
	OnPickupReady();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AHealthPickup::HandleOverlap);
	
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

void AHealthPickup::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsValid(OtherActor) || OtherComp != OtherActor->GetRootComponent())
	{
		return;
	}

	if (!CanBePickedUp())
	{
		return;
	}

	UHealthComponent* HealthComp = OtherActor->FindComponentByClass<UHealthComponent>();
	if (!HealthComp || HealthComp->IsFull())
	{
		return;
	}

	HealthComp->Heal(HealAmount);
	--UsesLeft;
	OnPickedUp(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("Health: %.1f, Heal Amount: %.1f"), HealthComp->GetHealth(), HealAmount);

	if (UsesLeft <= 0)
	{
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Health pick destroyed."));

	}
}

#pragma once

#include "GameFramework/PlayerController.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"

#include "MinimalGASDemoPlayerController.generated.h"

UCLASS(BlueprintType)
class AMinimalGASDemoPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void AcknowledgePossession(APawn* P)
	{
		Super::AcknowledgePossession(P);

		if (IAbilitySystemInterface* Character = Cast<IAbilitySystemInterface>(P))
		{
			Character->GetAbilitySystemComponent()->InitAbilityActorInfo(P, P);
		}
	}
};

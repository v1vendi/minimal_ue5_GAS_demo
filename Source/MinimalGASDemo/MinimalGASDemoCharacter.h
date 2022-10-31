#pragma once

#include "ThirdPersonTemplateCharacter.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"


#include "MinimalGASDemoCharacter.generated.h"

UCLASS(BlueprintType)
class AMinimalGASDemoCharacter : public AThirdPersonTemplateCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AMinimalGASDemoCharacter()
	{
		AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
		AbilitySystemComponent->SetIsReplicated(true);
	}

	UPROPERTY(BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	virtual void PossessedBy(AController* NewController) override
	{
		Super::PossessedBy(NewController);

		if (AbilitySystemComponent)
		{
			AbilitySystemComponent->InitAbilityActorInfo(this, this);
		}
		// ASC MixedMode replication requires that the ASC Owner's Owner be the Controller.
		SetOwner(NewController);
	}
};

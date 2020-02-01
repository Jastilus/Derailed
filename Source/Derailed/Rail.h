#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rail.generated.h"

UCLASS()
class DERAILED_API ARail : public AActor
{

	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplineController")
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplineController")
		class USplineComponent* Spline;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "SplineController")
		TSubclassOf<class AActor> ActorToMoveClass;

	class AActor* ActorToMove;

protected:

	UPROPERTY(EditAnywhere, Category = "SplineController")
		float TotalPathTimeController;

	UPROPERTY(EditAnywhere, Category = "SplineController")
		bool bSplineInLoop;

	bool bCanMoveActor;

	float StartTime;

public:

	ARail();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};

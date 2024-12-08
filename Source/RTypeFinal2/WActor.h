// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PoolActor.h"
#include "Components/CapsuleComponent.h"
#include "Niagara/Public/NiagaraComponent.h"
#include "WActor.generated.h"

UCLASS(Blueprintable)
class RTYPEFINAL2_API AWActor : public APoolActor
{
	GENERATED_BODY()
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
        USceneComponent* RootNode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
        UCapsuleComponent* Collision_A;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
        UNiagaraComponent* NS_Body;

public:
    AWActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
        void OnOverlapEnemyBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION(BlueprintCallable)
        void OnHitLand(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& hit);
};

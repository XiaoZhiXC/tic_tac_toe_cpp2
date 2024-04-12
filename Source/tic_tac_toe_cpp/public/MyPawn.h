// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KismetStringLibrary.generated.h"
#include "kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "MyPawn.generated.h"

#define COM -1 
#define MAN 1
#define STEP 9 
#define DRAW 0 
#define ROW 3 
#define COL 3
#define MAX_NUM 1000;

USTRUCT(BlueprintType)
struct FMove
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int X;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int Y;
};

UCLASS()
class TIC_TAC_TOE_CPP_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int A1 =1;
	int Board[3][3] = { { 0,0,0 },
					{ 0,0,0 },
					{ 0,0,0 }
	};
	int TempBoard[3][3] = { { 0,0,0 },
						{ 0,0,0 },
						{ 0,0,0 }
	};
	//玩家
	int Player = MAN;
	//最好的一步
	FMove BestMove;
	//当前深度
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int CurrentDepth=9;
	//随机步数
	int RandomMove;
	//难度
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int DifficultLevel=1;
	//谁先走
	bool bMAN_First = true;

	int TempDepth = 9;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 A2 =1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector A3;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector2D A5;
	
	FVector2d A4;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FMove Move;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, Category = "XiaoZhiXC")
	int32 Addby(int32 Ass = 1, int32 Bss = 1);
	UFUNCTION(BlueprintCallable, Category = "XiaoZhiXC")
	FMove GetFVector2D(TArray<FVector> B1);
	UFUNCTION(BlueprintCallable, Category = "XiaoZhiXC")
	int IsWin();
	UFUNCTION(BlueprintCallable, Category = "XiaoZhiXC")
	int EvaluteMap();
	int GetMoveList(FMove MoveList[]);

	int MiniMaxsearch(int Depth);
	UFUNCTION(BlueprintCallable, Category = "XiaoZhiXC")
	void UpdateBoard(TArray<FVector> B1);
	UFUNCTION(BlueprintCallable, Category = "XiaoZhiXC")
	int IsGameOver(TArray<FVector> B1);
	
};


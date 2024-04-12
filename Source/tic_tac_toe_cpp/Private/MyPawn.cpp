// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
//#include "kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
//#include "Engine/Internal/Kismet/BlueprintTypeConversions.h"


//int32 Ga1=2;
// struct FMove
// {
// 	int X;
// 	int Y;
//  
// };


// Sets default Values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 AMyPawn::Addby(int32 Ass, int32 Bss )
{
	//return Ass+Bss+1;
	A3.X=COM;
	A4.X=1;
	return Board[0][1];
}


int AMyPawn::IsWin() {
	//int i, j;
 
	for (int i = 0; i < 3; i++)
	{
		if (Board[i][0] + Board[i][1] + Board[i][2] == 3)
			return 1;
		else if (Board[i][0] + Board[i][1] + Board[i][2] == -3)
			return -1;
	}
	for (int j = 0; j < 3; j++)
	{
		if (Board[0][j] + Board[1][j] + Board[2][j] == 3)
			return 1;
		else if (Board[0][j] + Board[1][j] + Board[2][j] == -3)
			return -1;
	}
	if (Board[0][0] + Board[1][1] + Board[2][2] == 3 || Board[0][2] + Board[1][1] + Board[2][0] == 3)
		return 1;
	else if (Board[0][0] + Board[1][1] + Board[2][2] == -3 || Board[0][2] + Board[1][1] + Board[2][0] == -3)
		return -1;
	else  return 0;
 
}

//评估函数，如果计算机赢了，返回大值 
int AMyPawn::EvaluteMap() {
 
	//bool flag = true;
	int i, j;
 
	if (IsWin() == COM)
		return MAX_NUM;//如果计算机赢了，返回最大值 
	if (IsWin() == MAN)
		return -MAX_NUM;//如果计算机输了，返回最小值 
	int count = 0;//该变量用来表示评估函数的值
	//将棋盘中的空格填满自己的棋子，既将棋盘数组中的0变为1
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (Board[i][j] == 0)
				TempBoard[i][j] = COM;
			else
				TempBoard[i][j] = Board[i][j];
		}
	//电脑一方
	//计算每一行中有多少行的棋子连成3个的
	for (i = 0; i < 3; i++)
		count += (TempBoard[i][0] + TempBoard[i][1] + TempBoard[i][2]) / 3;
	for (i = 0; i < 3; i++)
		count += (TempBoard[0][i] + TempBoard[1][i] + TempBoard[2][i]) / 3;
	count += (TempBoard[0][0] + TempBoard[1][1] + TempBoard[2][2]) / 3;
	count += (TempBoard[2][0] + TempBoard[1][1] + TempBoard[0][2]) / 3;
	//将棋盘中的空格填满对方的棋子，既将棋盘数组中的0变为-1
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (Board[i][j] == 0)
				TempBoard[i][j] = MAN;
			else TempBoard[i][j] = Board[i][j];
		}
	//对方
	//计算每一行中有多少行的棋子连成3个的
	for (i = 0; i < 3; i++)
		count += (TempBoard[i][0] + TempBoard[i][1] + TempBoard[i][2]) / 3;
	for (i = 0; i < 3; i++)
		count += (TempBoard[0][i] + TempBoard[1][i] + TempBoard[2][i]) / 3;
	count += (TempBoard[0][0] + TempBoard[1][1] + TempBoard[2][2]) / 3;
	count += (TempBoard[2][0] + TempBoard[1][1] + TempBoard[0][2]) / 3;
	return -count;
}

//获取可移动格子
int AMyPawn::GetMoveList(FMove MoveList[]) {
	int MoveCount = 0;
	//int i, j;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board[i][j] == 0)
			{
				MoveList[MoveCount].X = i;
				MoveList[MoveCount].Y = j;
				MoveCount++;
			}
 
		}
	}
	return MoveCount; //返回一共多少个空的位置 
}

int AMyPawn::MiniMaxsearch(int Depth)
{
	int Value;  //估值 
	int BestValue = 0; //最好的估值
	int MoveCount = 0;
	
	int i; //int m, n;
	FMove MoveList[9];//保存可以下子的位置
	if (IsWin() == COM || IsWin() == MAN)
	{
		return EvaluteMap();  
	}
	//一共多少步
	MoveCount = GetMoveList(MoveList);
	
	if(DifficultLevel==1)
	{
		RandomMove=UKismetMathLibrary::RandomIntegerInRange(0,MoveCount-1);
		BestMove = MoveList[RandomMove];
		return 0;
	}
	//如果搜索深度耗尽 ， 返回估值 
	if (Depth == 0)
	{
		return EvaluteMap();
	}
 
 
	//根据不同的玩家 进行赋值 
	if (COM == Player) {
		BestValue = -MAX_NUM;
	}
	else if (MAN == Player)
	{
		BestValue = MAX_NUM;
	}
 
	

	
	// std::srand(std::time(nullptr));
	// int s=rand();
	// s=rand()+s;
	// s=(rand()+s)%MoveCount;
	// //printf("s",%s);
	// cout << s;
	if (Depth == TempDepth)
	{
		RandomMove=UKismetMathLibrary::RandomIntegerInRange(0,MoveCount-1);
		BestMove = MoveList[RandomMove];
	}
 
	for (i = 0; i < MoveCount; i++)
	{
		FMove CurMove = MoveList[i];
 
		//makeMove(CurMove);
		Board[CurMove.X][CurMove.Y] = Player;
		Player = (Player == COM) ? MAN : COM;
		Value = MiniMaxsearch(Depth - 1);
		//unMakeMove(CurMove);
		Board[CurMove.X][CurMove.Y] = 0;
		Player = (Player == COM) ? MAN : COM;
 
		if (Player == COM)
		{
			if (Value > BestValue)
			{
				BestValue = Value;
				if (Depth == TempDepth)
				{
					BestMove = CurMove;
				}
			}
		}
		else if (Player == MAN)
		{
			if (Value < BestValue)
			{
				BestValue = Value;
				if (Depth == TempDepth)
				{
					BestMove = CurMove;
				}
			}
		}
 
	}
	 
	return BestValue;
}

//FVector2D AMyPawn::GetFVector2D(FVector B1,FVector B2,FVector B3)
FMove AMyPawn::GetFVector2D(TArray<FVector> B1)
{
	
	for(int i=0;i<3;i++)
	{
		Board[i][0]=B1[i].X;
		Board[i][1]=B1[i].Y;
		Board[i][2]=B1[i].Z;
	}
	Player = COM;
	// if(DifficultLevel==2)
	// {
	// 	TempDepth=1;
	// }
	// else
	// {
	// 	TempDepth=3;
	// }
	TempDepth=DifficultLevel-1;
	if(CurrentDepth>TempDepth){
		//TempDepth=3;
		MiniMaxsearch(TempDepth);
	}
	else{
		TempDepth = CurrentDepth;
		MiniMaxsearch(CurrentDepth);
	}
	//BestMove.X=1;
	//BestMove.X=99;
	
	return BestMove;
}

void AMyPawn::UpdateBoard(TArray<FVector> B1)
{
	for(int i=0;i<3;i++)
	{
		Board[i][0]=B1[i].X;
		Board[i][1]=B1[i].Y;
		Board[i][2]=B1[i].Z;
	}
}

int AMyPawn::IsGameOver(TArray<FVector> B1)
{
	//bool IsGameO=false;
	int MoveCount1=0;
	for(int i=0;i<3;i++)
	{
		Board[i][0]=B1[i].X;
		Board[i][1]=B1[i].Y;
		Board[i][2]=B1[i].Z;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Board[i][j] == 0)
			{
				MoveCount1++;
			}
 
		}
	}
	
	if(IsWin()==0)
	{
		if (MoveCount1==0)
		{
			return 2;
		}
		return 0;
	}
	else
	{
		return IsWin();
	}
	//return 0;
	
}

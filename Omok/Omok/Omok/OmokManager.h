#pragma once
#include <iostream>
#include "Globar.h"
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class OmokManager
{
private:
	int board[BOARD_X][BOARD_Y] = { BoardType::Empty };
	

public:
	void ShowMenu();
	void Draw();
	void Play();
	void RePlay();
	GameState CheckEnd();
	void SetAI(void(*pAIAttack)(int *x, int *y), void(*pAIDefence)(int x, int y));

private:
	int		CheckX(int x, int y, BoardType type);
	int		CheckY(int x, int y, BoardType type);
	int		CheckXY(int x, int y, BoardType type);
	void	BoardClear();
	void	PutStone(int &bw, int x, int y);
	void	(*AIAttack)(int *x, int *y);
	void	(*AIDefence)(int x, int y);
};
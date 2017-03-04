#pragma once

const int BOARD_X = 19;
const int BOARD_Y = 19;

enum BoardType
{
	Empty,
	Black,
	White,
	Count = 10,
	Count2 = 20,
	Count3 = 30,
	Count4 = 40,
	Count5 = 50,
};

enum GameState
{
	None		= -1,
	WinBlack	= 100,
	WinWhite	= 200,
};
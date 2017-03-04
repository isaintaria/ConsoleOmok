#pragma once

const int BOARD_X = 19;
const int BOARD_Y = 19;

enum BoardType
{
	Empty,
	Black,
	White
};

enum GameState
{
	None = -1,
	WinBlack = 100,
	WinWhite = 200,
};
#pragma once
#include <iostream>

class Algorithms{
	private:
		static int evaluateBoard(std::string (&board)[3][3]);
		static bool gameOver(std::string (&board)[3][3]);
		static std::string checkWinner(std::string (&board)[3][3]);

	public:
		static int minimax(std::string (&board)[3][3], int depth, bool isMaximizing);

};

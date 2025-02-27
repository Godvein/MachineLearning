#include "algorithms.h"
#include "game.h"
#include <limits>

//fuction to evaluate the position
int Algorithms::evaluateBoard(std::string (&board)[3][3]){
	int score = 0;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == "X")
				score ++;
			if(board[i][j] == "O")
				score--;
		}
	}
	return score;
}

//function to check winner
std::string Algorithms::checkWinner(std::string (&board)[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){

			//check horizontal
			if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
				return board[i][0];

			//check vertical
			if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
				return board[0][j];

			//check left diagonal
			if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
				return board[0][0];

			//check right diagonal
			if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
				return board[0][2];
		}
	}
	return "n";
}

//function to check if gameover
bool Algorithms::gameOver(std::string (&board)[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == "")
				return false;
		}
	}
	return true;
}

int Algorithms::minimax(std::string (&board)[3][3], int depth, bool isMaximizing){

	std::string winner = checkWinner(board);

	//base case
	//X wins evaluation 1
	if(winner == "X"){
		return 10 + depth;
	}
	//O wins evaluation -1
	else if(winner == "O"){
		return -10 - depth;
	}
	//draw evaluation 0
	else if(gameOver(board)){
		return 0;
	}
	//if depth reached
	if(depth == 0){
		return evaluateBoard(board);
	}
	if(isMaximizing){
		//maxinum evaluation
		int max_eval = std::numeric_limits<int>::min();

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(board[i][j] == ""){
					board[i][j] = "X";
					int eval = minimax(board, depth-1, false);
					board[i][j] = "";
					if(eval > max_eval){
						max_eval = eval;
					}

				}
			}
		}
		return max_eval;
	}
	else{
		//minimum evaluation
		int min_eval = std::numeric_limits<int>::max();

		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(board[i][j] == ""){
					board[i][j] = "O";
					int eval = minimax(board, depth-1, true);
					board[i][j] = "";
					if(eval < min_eval){
						min_eval = eval;
					}

				}
			}
		}
		return min_eval;
	}

}

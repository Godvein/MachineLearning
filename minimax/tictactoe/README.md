# Tic-Tac-Toe with Minimax Algorithm  

This project is an implementation of the classic Tic-Tac-Toe game using the **Minimax algorithm** for AI decision-making. The goal is to create an unbeatable AI opponent that plays optimally in every situation.  

## Minimax Algorithm Overview  

The **Minimax algorithm** is a decision-making algorithm used in two-player turn-based games like Tic-Tac-Toe, Chess, and Connect Four. It follows these principles:  

1. **Maximizing Player (AI)** tries to get the highest possible score.  
2. **Minimizing Player (Human)** tries to force the lowest possible score for the AI.  
3. The algorithm explores all possible moves, evaluates board states, and selects the best possible move.  
4. It uses **recursion** to simulate future moves and assigns scores to different outcomes:  
   - **+1** for AI winning  
   - **-1** for Human winning  
   - **0** for a draw  

This ensures that the AI never loses and always plays optimally.  

## Project Goals  

- Implement a **graphical Tic-Tac-Toe** game using **SFML**.  
- Develop an AI opponent using the **Minimax algorithm**.  
- Ensure the AI plays optimally, making it unbeatable.  

## Technologies Used  

- **C++** for core logic  
- **SFML** for rendering the game board and handling input  
- **Minimax Algorithm** for AI decision-making  


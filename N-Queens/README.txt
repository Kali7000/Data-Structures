N-Queens Problem
Name: Vishal Wagh

This program solves the N-Queens problem using stacks on a user defined number of queens. 
I had to use vectors to represent the chess board, i did use stacks to store the position of the queens

-----------------------------------------------------------------------------

##TO RUN:
using cmd, run make.exe in your command prompt then use make run to run the program, and make clean to clean the program 

------------------------------------------------------------


How the Code Works
---------------------

1. Grid Representation:  
   The chessboard is represented by a 2D vector `position[N][N]`. Initially, all the cells are set to `0` (empty). When a queen is placed, the corresponding cell is set to `1`.

2. isValid Function:  
   This function checks whether a queen can be placed at a specific position. It checks:
   - If there's another queen in the same column.
   - If there's another queen on the left diagonal.
   - If there's another queen on the right diagonal.
   If any of these conditions are true, the position is invalid, and it returns `false`.

3. Backtracking (N_Queens Function):  
   The program uses a recursive backtracking approach:
   - It tries to place a queen in each row.
   - For each row, it checks every column to see if placing the queen is valid using the `isValid` function.
   - If a valid position is found, the queen is placed, and the program moves on to the next row.
   - If no valid position is found in the next row, it backtracks (removes the previously placed queen) and tries the next possible position in the previous row.
   - This continues until either all queens are placed (solution found) or all possibilities are exhausted (no solution).

4. Stack Usage:  
   A stack `queens` is used to store the positions of the queens as pairs of (row, column). This helps in tracking the positions and backtracking efficiently.

5. printGrid Function:  
   After placing all queens successfully, this function prints the final chessboard with the queens' positions marked as `1`.

6. Main Function:  
   - The main function reads the input (number of queens, `N`).
   - It initializes the grid and calls the `N_Queens` function to attempt solving the problem.
   - If a solution is found, it prints the chessboard using `printGrid`. If no solution exists, it outputs a message.


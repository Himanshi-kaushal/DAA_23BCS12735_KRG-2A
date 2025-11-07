/*
Title: Sudoku Solver: Backtracking Algorithms for Puzzles of Every Complexity
Domain: Logic Puzzles, AI
Description: Create a program that uses backtracking algorithms to solve Sudoku puzzles of varying difficulty levels
Hardware/Software Requirement: Programming environment (C++ compiler)
Technology: Backtracking algorithms, constraint satisfaction techniques
Objective: Provide a solution to solve Sudoku puzzles of varying difficulties
Targeted Outcome: Ability to solve Sudoku puzzles algorithmically

Algorithm:

1. Represent the Sudoku board as a 9x9 integer matrix where empty cells are 0.
2. Find an unassigned cell (row, col). If none, the board is solved.
3. For digits d from 1 to 9:
   a. If placing d at (row, col) does not violate row, column, and 3x3 box constraints, place d.
   b. Recursively attempt to solve the updated board.
   c. If recursion returns true, solution found; return true.
   d. Otherwise set cell back to 0 (backtrack) and try next digit.
4. If no digit 1..9 can be placed successfully, return false (trigger backtracking).
5. Use simple heuristics optionally: choose the empty cell with the fewest legal moves (minimum remaining values) to speed up solving.
*/

#include <bits/stdc++.h>
using namespace std;
bool usedInRow(int grid[9][9], int row, int num) {
    for (int col = 0; col < 9; ++col) if (grid[row][col] == num) return true;
    return false;
}
bool usedInCol(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; ++row) if (grid[row][col] == num) return true;
    return false;
}
bool usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int r = 0; r < 3; ++r) for (int c = 0; c < 3; ++c) if (grid[boxStartRow + r][boxStartCol + c] == num) return true;
    return false;
}
bool isSafe(int grid[9][9], int row, int col, int num) {
    return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3, col - col % 3, num);
}
bool findUnassignedLocation(int grid[9][9], int &row, int &col) {
    int bestR = -1, bestC = -1, bestCount = 10;
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (grid[r][c] == 0) {
                int count = 0;
                for (int num = 1; num <= 9; ++num) if (isSafe(grid, r, c, num)) ++count;
                if (count < bestCount) { bestCount = count; bestR = r; bestC = c; if (count == 1) { row = bestR; col = bestC; return true; } }
            }
        }
    }
    if (bestR == -1) return false;
    row = bestR; col = bestC;
    return true;
}
bool solveSudoku(int grid[9][9]) {
    int row, col;
    if (!findUnassignedLocation(grid, row, col)) return true;
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
void printGrid(int grid[9][9]) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            cout << grid[r][c];
            if (c < 8) cout << " ";
        }
        cout << "\n";
    }
}
int main() {
    int grid[9][9];
    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) grid[i][j] = 0;
    cout << "Enter Sudoku (9 lines with 9 numbers, use 0 for empty cells):\n";
    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) cin >> grid[i][j];
    clock_t start = clock();
    bool solved = solveSudoku(grid);
    clock_t end = clock();
    if (solved) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    } else cout << "No solution exists\n";
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_taken << " seconds\n";
    return 0;
}


/*
Sample Run:

Input:

Enter Sudoku (9 lines with 9 numbers, use 0 for empty cells):
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9


Output:

Solved Sudoku:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
Time taken: 0.000020 seconds
*/

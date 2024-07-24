
//NAME-CHETAN BHAVSAR
//ROLL NO-22074009
//BRANCH-CSE IDD



#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

const int N = 9;
const int UNASSIGNED = 0;

// Cell structure to represent each cell in Sudoku
struct Cell {
    int row, col, val;
    int heuristic; // Heuristic value for A* search

    Cell(int r, int c, int v, int h) : row(r), col(c), val(v), heuristic(h) {}

    bool operator<(const Cell& other) const {
        return heuristic > other.heuristic; // Min-heap based on heuristic value
    }
};

// Function to check if a number can be placed in the given cell without conflicts
bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check subgrid
    int sqrtN = sqrt(N);
    int subgridRowStart = row - row % sqrtN;
    int subgridColStart = col - col % sqrtN;
    for (int i = 0; i < sqrtN; ++i) {
        for (int j = 0; j < sqrtN; ++j) {
            if (board[subgridRowStart + i][subgridColStart + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to find the next empty cell in the board
bool findEmptyCell(vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (board[row][col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

// Function to calculate the heuristic value for a cell (number of empty cells in its row, column, and subgrid)
int calculateHeuristic(vector<vector<int>>& board, int row, int col) {
    int heuristic = 0;
    int sqrtN = sqrt(N);
    int subgridRowStart = row - row % sqrtN;
    int subgridColStart = col - col % sqrtN;

    // Check row
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == UNASSIGNED) heuristic++;
    }

    // Check column
    for (int i = 0; i < N; ++i) {
        if (board[i][col] == UNASSIGNED) heuristic++;
    }

    // Check subgrid
    for (int i = 0; i < sqrtN; ++i) {
        for (int j = 0; j < sqrtN; ++j) {
            if (board[subgridRowStart + i][subgridColStart + j] == UNASSIGNED) heuristic++;
        }
    }

    return heuristic;
}

// A* algorithm to solve Sudoku
bool solveSudoku(vector<vector<int>>& board) {
    priority_queue<Cell> pq;

    // Add initial empty cells to the priority queue with heuristics
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == UNASSIGNED) {
                int heuristic = calculateHeuristic(board, i, j);
                pq.push(Cell(i, j, UNASSIGNED, heuristic));
            }
        }
    }

    // Main loop
    while (!pq.empty()) {
        Cell cell = pq.top();
        pq.pop();

        if (cell.val != UNASSIGNED) {
            continue; // Cell already filled, skip
        }

        int row = cell.row;
        int col = cell.col;

        // Try placing each possible value
        for (int num = 1; num <= N; ++num) {
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                if (solveSudoku(board)) {
                    return true; // Puzzle solved recursively
                }
                board[row][col] = UNASSIGNED; // Undo the placement
            }
        }

        // If no solution found, backtrack
        return false;
    }

    return true; // All cells filled, puzzle solved
}

// Function to print the Sudoku board
void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        cout << "Sudoku puzzle solved successfully:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the Sudoku puzzle." << endl;
    }

    return 0;
}
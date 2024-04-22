#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, const vector<vector<bool>> &board,
            vector<bool> &rowAttacked, vector<bool> &colAttacked,
            vector<bool> &leftDiagAttacked, vector<bool> &rightDiagAttacked)
{
    int N = board.size();

    // Check row, column, diagonal attacks based on pre-computed information
    return !rowAttacked[row] && !colAttacked[col] && !leftDiagAttacked[row - col + N - 1] &&
           !rightDiagAttacked[row + col];
}

void updateAttacks(int row, int col, vector<bool> &rowAttacked, vector<bool> &colAttacked,
                   vector<bool> &leftDiagAttacked, vector<bool> &rightDiagAttacked, bool add)
{
    int N = rowAttacked.size();

    rowAttacked[row] = add;
    colAttacked[col] = add;
    leftDiagAttacked[row - col + N - 1] = add;
    rightDiagAttacked[row + col] = add;
}

int solveNQueens(vector<vector<bool>> &board, int col,
                 vector<bool> &rowAttacked, vector<bool> &colAttacked,
                 vector<bool> &leftDiagAttacked, vector<bool> &rightDiagAttacked)
{
    int N = board.size();
    int solutions = 0;

    // Base case: All queens placed
    if (col == N)
    {
        // Print a solution (optional)
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    // Try placing queen in each row of this column
    for (int row = 0; row < N; row++)
    {
        if (isSafe(row, col, board, rowAttacked, colAttacked, leftDiagAttacked, rightDiagAttacked))
        {
            board[row][col] = true;
            updateAttacks(row, col, rowAttacked, colAttacked, leftDiagAttacked, rightDiagAttacked, true);

            solutions += solveNQueens(board, col + 1, rowAttacked, colAttacked, leftDiagAttacked, rightDiagAttacked);

            board[row][col] = false; // Backtrack
            updateAttacks(row, col, rowAttacked, colAttacked, leftDiagAttacked, rightDiagAttacked, false);
        }
    }

    return solutions;
}

int main()
{
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    // Dynamically create the boolean board
    vector<vector<bool>> board(N, vector<bool>(N, false));

    vector<bool> rowAttacked(N, false), colAttacked(N, false), leftDiagAttacked(2 * N - 1, false),
        rightDiagAttacked(2 * N - 1, false);

    int solutions = solveNQueens(board, 0, rowAttacked, colAttacked, leftDiagAttacked, rightDiagAttacked);

    if (solutions == 0)
    {
        cout << "Solution does not exist";
    }
    else
    {
        cout << "Total solutions: " << solutions << endl;
    }

    return 0;
}
#include<iostream>
#include <vector>
using namespace std;


class NQueen
{

int n;
public:
NQueen(int val){n=val;}

void display(vector<vector<char>>&board)
{
    for(int i = 0 ; i<n;i++)
    {
        for(int j = 0 ; j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void bnb()
{
     vector<vector<char>>board(n , vector<char>(n , '.'));
    vector<int>remainingRows(n , 0);
    vector<int>upperDiagonal(2*n - 1 , 0);
    vector<int>lowerDiagonal(2*n - 1 , 0);
    return bnbSolver(0 , remainingRows , lowerDiagonal , upperDiagonal , board);
   
}

void bnbSolver(int col , vector<int> & remainingRows , vector<int>lowerDiagonal ,    vector<int>upperDiagonal , vector<vector<char>> &board)
{ 
 if(col==n)
    {
        display(board);
        return;
        
    }
    for(int row = 0 ; row<n;row++)
    {
        if(remainingRows[row]==0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1 - row + col] == 0)
        {
            board[row][col] = 'Q';
            remainingRows[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1 + col - row] = 1;
            bnbSolver(col + 1 , remainingRows, lowerDiagonal,upperDiagonal, board);
             board[row][col] = '.';
            remainingRows[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n- 1 + col -row] = 0;
        }
    }
  
}
};




int main()
{
    cout<<"Enter the number of queens : ";
    int n;
    cin>>n;
    if(n==2 || n==3) cout<<"terminal states"<<endl;
    NQueen obj(n);
    // obj.backtracking();
    // return 0;
    obj.bnb();
}
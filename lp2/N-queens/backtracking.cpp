#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row,int col,vector<string> board,int n){
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=duprow;
    col=dupcol;
    while (col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }
    col=dupcol;
    row=duprow;
    while (row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> board(n);
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}

int main(){
    int n;
    cout<<"Enter No. of Queens you want to place : ";
    cin>>n;
    if(n==2 || n==3) cout<<"It is not possible to place "<<n<<" queens in "<<n<<"x"<<n<<"grid"<<endl;
    vector<vector<string>> ans=solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        cout<<"Arrangement "<<i+1<<endl;
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
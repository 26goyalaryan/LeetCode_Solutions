class Solution {
    // this is brute force and has extra time complexity of checking 3 rimes he collision.
    // in optimised approach, we will use hashing of a vector and if it is alrady hashed, 
    // no need further. we simply dont add the Q.
public:
    // driver code
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s; // making each row in board empty
        }
        solve(0,board,ans,n);
        return ans;
    }
public: void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    if(col==n){
        ans.push_back(board); // insert the final chess board in the ans
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n); // call for next recursion for next column.
            board[row][col]='.'; // backtrack and return unaltered board.
        }
    }
}
public: bool isSafe(int row,int col,vector<string> &board,int n){
    // for upper diagonal
    int ogrow=row,ogcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q')
            return false; // ie upper diagonal has Q so 3rd condition will not be valid
        row--;
        col--;
    }
    col=ogcol;
    row=ogrow;
    // check for left collision
    while(col>=0){
        if(board[row][col]=='Q')
            return false;
        col--;
    }
    // for lower left diagonal
    row=ogrow;
    col=ogcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q')
            return false;
        row++;col--;
    }
    return true;
}    
};
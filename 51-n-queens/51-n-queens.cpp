class Solution {
    // brute force and has extra time complexity of checking 3 rimes he collision.
    // in optimised approach, we will use hashing of a vector and if it is alrady hashed, 
    // no need further. we simply dont add the Q.
    
    /*
    ---> for left collision:
        we found that if the row has already a Q, we will has hash for particular row.
    
    ---> for lower leftdiagonal:
        we trace the pattern that (row+col) sum is same diagonally,
        so will hash the particular sum for corresponding row and col and check it later
        if sum is not 0, ie there is some pair exist which produces the same sum has a Queen.
    
    ---> for upper leftdiagonal:
        same process follows but now the hashing will be done for (n-1+col-row)
    */
public:
    // driver code
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s; // making each row in board empty
        }
        // hasings declared to check validity.
        vector<int> 
            leftRow(n, 0), 
            upperDiagonal(2 * n - 1, 0), 
            lowerDiagonal(2 * n - 1, 0);
        solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
        return ans;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n){
        if(col==n){
            ans.push_back(board); // insert the final chess board in the ans
            return;
        }
        for(int row=0;row<n;row++){
            
            //check for validity of the place
            
            if(leftRow[row]==0 &&
              upperDiagonal[row+col]==0 &&
              lowerDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                upperDiagonal[row+col]=1;
                lowerDiagonal[n-1+col-row]=1;
                
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                
                // backtrack and unalter the changes
                board[row][col]='.';
                leftRow[row]=0;
                upperDiagonal[row+col]=0;
                lowerDiagonal[n-1+col-row]=0;
            }
        }
    }
    
/*


brute force


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
    */
};
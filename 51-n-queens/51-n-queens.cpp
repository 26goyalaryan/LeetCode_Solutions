class Solution {
public:
    // driver code
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s; // making each row in board empty
        }
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
};
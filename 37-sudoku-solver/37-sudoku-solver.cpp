class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]=='.'){
                    // if found any blank space.
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){ 
        // will try every 1-->9 to fill empty position and call function again for next empty
                            board[i][j]=c;
                            if(solve(board)==true) // recursive call 
                                return true;
                            else
                                board[i][j]='.'; // backtracking
                        }
                    }
                return false;
                }
            }
        }
            
        return true; // ie we didnt find any blank space, base case.
    }
    
    bool isvalid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++) // loop over indices in board
        {
            if(board[row][i]==c)
                return false; 
            // check in row- horizontally
            if(board[i][col]==c)
                return false;
            // check in column- vertically
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
            // check in 3*3 box.
        }
        return true;
    }
};
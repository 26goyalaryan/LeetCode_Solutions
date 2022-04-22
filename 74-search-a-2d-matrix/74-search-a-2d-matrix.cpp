class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0,col=cols-1; // point on last element in first row.
        while(row<rows && col>=0){
            if(matrix[row][col]==target)
                return true;
            if(target>matrix[row][col])
                //since the target is greater, we need to move in next row.
                //bcz it is impossible to find in same row towards left as last element is                       //already smaller
                
                row++; // ie move right in bst
            else 
                col--; // ie move left in bst
        }
        return false;
    }
};
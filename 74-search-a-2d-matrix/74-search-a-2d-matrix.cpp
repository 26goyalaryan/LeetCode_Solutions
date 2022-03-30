class Solution {
    /*
    intution behind solving the problem in On is treating it as a binary search tree
                     7
                5         20
            3        16        60
            
         1      11        34
            
            10       30
            
            
    we start from [0][col-1] and keep decreasing the col to check first row 
        if target < nums[0][col-1]
    else move right ie row++;
    */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0,col=cols-1; // point on last element in first row.
        while(row<rows && col>=0){
            if(matrix[row][col]==target)
                return true;
            if(target>matrix[row][col])
                row++; // ie move right in bst
            else 
                col--; // ie move left in bst
        }
        return false;
    }
};
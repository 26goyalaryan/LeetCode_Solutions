class Solution {
/*
    we will first convert the 2d array to 1d array
    find the new 1d index 
    update it with k
    and then update ans vector back
    
    the index of 2d element at [i][j] in 1d is (i*n+j) n=total columns
    the index of 1d elemnt in 2d array is [curr 1d index / n][curr 1d index % n];

*/
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oneDindex=((i*n+j)+k)%(m*n);
                // %(m*n) bcz the value of k may be large and index may go out of bound
                int newRow=(oneDindex/n);
                int newCol=(oneDindex%n);
                ans[newRow][newCol]=grid[i][j];
            }
        }
        return ans;
    }
};
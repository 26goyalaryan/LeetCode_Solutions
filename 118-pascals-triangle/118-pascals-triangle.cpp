class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            // every nth row has n columns
            ans[i][0]=ans[i][i]=1;
            // first and last element of every row is 1.
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j]; 
                // every element is sum of previous 2 colums of previous row
            }
        }
        return ans;
    }
};
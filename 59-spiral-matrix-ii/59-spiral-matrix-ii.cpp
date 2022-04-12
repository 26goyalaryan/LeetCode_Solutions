class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int> (n));
        int t=0,d=n-1,r=n-1,l=0;
        int dir=0;
        int e=1;
        while(t<=d && l<=r){
            for(int i=l;i<=r;i++){
                ans[t][i]=e;
                e++;
            }
            t++;
            for(int i=t;i<=d;i++){
                ans[i][r]=e;
                e++;
            }
            r--;
            for(int i=r;i>=l;i--){
                ans[d][i]=e++;
            }
            d--;
            for(int i=d;i>=t;i--){
                ans[i][l]=e;
                e++;
            }
            l++;
        }
        return ans;
    }
};
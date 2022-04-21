class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        vector<vector<int>> ans;
        int j=0;
        sort(intr.begin(),intr.end()); // sorting the intervals so that we can compare
        ans.push_back(intr[0]); // pushing first element and pointing j on it.
        for(int i=1;i<intr.size();i++){
            if(ans[j][1]>=intr[i][0]){
                ans[j][1]=max(ans[j][1],intr[i][1]);
                // not incrementing j bcz may be the next interval can be merged.
            }
            else{
                ans.push_back(intr[i]);
                j++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        int n=a.size();
        int i=0;
        while(i<n){
            if(a[i][0]<b[0])
                ans.push_back(a[i++]);
            else
                break;
        }
        if(ans.size()==0 || ans.back()[1]<b[0])
            ans.push_back(b);
        else
            ans.back()[1]=max(ans.back()[1],b[1]);
        // interval is starting with smallest 
        // or the last interval cant be merged with the b interval
        while(i<n){
            if(ans.back()[1]>=a[i][0])
                ans.back()[1] = max(ans.back()[1],a[i][1]);
            else
                ans.push_back(a[i]);
            i++;
        }
        return ans;
    }
};
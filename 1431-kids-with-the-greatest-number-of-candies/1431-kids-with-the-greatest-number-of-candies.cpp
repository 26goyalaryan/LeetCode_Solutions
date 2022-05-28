class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int n) {
        vector<bool> ans;
        int maxi=INT_MIN;
        for(int i=0;i<candies.size();i++){
            maxi=max(candies[i],maxi);
        }
        for(auto it:candies){
            if(it+n >= maxi)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
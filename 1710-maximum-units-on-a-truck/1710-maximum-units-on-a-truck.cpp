class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        
        // push according to max units of items in a particular box
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][1],nums[i][0]});
        }
        int ans=0;
        int curr=0;
        while(!pq.empty()){
            
            // curr is used to select the allowed boxes we can pick
            curr=min(pq.top().second,k);
            
            ans+=(pq.top().first*curr);
            k-=curr;
            
            // if no box left, break out ie we have pushed allowed no. of boxes
            pq.pop();
            if(!k)
                break;
        }
        return ans;
        
        // Time complexity - O(n)
        // space complexity - O(n)
    }
};
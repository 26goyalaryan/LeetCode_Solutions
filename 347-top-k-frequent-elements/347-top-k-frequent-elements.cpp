class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> map;
        for(int it : nums){
            map[it]++;
        } 
        for(auto it:map){
            pq.push({it.second, it.first});
            if(pq.size()>map.size() - k){
                // to push only k elements. rather using one more for loop.
                ans.push_back(pq.top().second);
                pq.pop();
           }
        }
        return ans;
    }
};
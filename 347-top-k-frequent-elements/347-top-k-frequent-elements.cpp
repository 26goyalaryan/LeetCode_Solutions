class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> map;
        for(int it : nums){
            map[it]++;
        } 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};
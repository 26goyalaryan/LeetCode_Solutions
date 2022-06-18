class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        
        // counting freq of each char
        for(auto it:s){
            mp[it]++;
        }
        string ans="";
        
        //pushing pair<char,freq> in queue order by first element of pair(by default)
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty()){
            
            // adding char == to its freq
            int temp=pq.top().first;
            while(temp--){
                ans.push_back(pq.top().second);
           }
            // poppig out after pushing it
            pq.pop();
        }
        return ans;
    }
};
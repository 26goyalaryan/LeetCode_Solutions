class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int max_freq=pq.top().first;
        if(s.size()<2*max_freq-1)
            return "";
        
        string ans="";
        while(!pq.empty()){
            auto top1=pq.top();
            pq.pop();
            ans+=top1.second;
            top1.first--;
            if(!pq.empty()){
                ans+=pq.top().second;
                auto top2=pq.top();
                pq.pop();
                top2.first--;
                if(top2.first)
                    pq.push({top2.first,top2.second});
            }
            if(top1.first)
                pq.push({top1.first,top1.second});
        }
        return ans;
    }
};
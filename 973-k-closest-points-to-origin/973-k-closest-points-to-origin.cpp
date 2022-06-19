class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        
        //declaring maxheap of pair<distance,vector<point>>
        
        priority_queue<pair<int,vector<int>>> pq;
        int i=0;
        for(auto it:p){
            int x = it[0]*it[0] + it[1]*it[1];
            pq.push({x,{it[0],it[1]}});
            if(pq.size() > k) 
                pq.pop();
            i++;
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            cout<<pq.top().first<<endl;
            pq.pop();
        }
        return ans;
    }
};
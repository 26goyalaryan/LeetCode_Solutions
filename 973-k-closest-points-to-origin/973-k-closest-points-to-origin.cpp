class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        
        for(int i=0;i<points.size();i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            
            // no need to takr sqrt bcz sqrt(10) > sqrt(8)
            
            int temp= (x1*x1) + (y1*y1);
            
            pq.push({temp,{x1,y1}});
            
            if(pq.size()>k)
                pq.pop();
            
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
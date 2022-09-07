class Solution {
public:
    int minRefuelStops(int target, int curr, vector<vector<int>>& s) {
        
        priority_queue<int,vector<int>> pq;
        
        int n=s.size();
        int i=0;
        int res=0;
        while(curr<target){
            while(i<n &&  curr >= s[i][0]){
                pq.push(s[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            
            curr += pq.top();
            pq.pop();
            res++;  
        }
        return res;
    }
};
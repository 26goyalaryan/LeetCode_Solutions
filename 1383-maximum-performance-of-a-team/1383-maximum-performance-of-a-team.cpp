class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
        
        int mod = 1e9+7;
        
        vector<pair<int,int>> v; // to relate efficienct,speed together
        
        for(int i=0;i<n;i++)
            v.push_back({eff[i],sp[i]});
        
        sort(v.rbegin(),v.rend()); // sort in descneding order of efficiency
        
        priority_queue<int,vector<int>,greater<int>> pq; // to store the speeds
        
        long ans=0,sum=0;
        
        for(int i=0;i<n;i++){
            
            int eff=v[i].first,spd=v[i].second;
            
            sum+=spd;
            
            pq.push(spd);
            
            if(pq.size()>k)
            {
                sum-=pq.top(); //removing the minimum speed from all k, we need to maximise speed
                pq.pop();
            }
            ans=max(ans,sum*eff);
        }
        return ans%mod;
    }
};
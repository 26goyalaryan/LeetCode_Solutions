class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        
        int sum=0;
        for(auto it:nums){
            pq.push(it);
            sum+=it;
        }
        
        while(k--){
            int temp=pq.top();
            pq.pop();
            
            sum-=temp/2;
            
            pq.push((temp+1)/2);
            
        }
        
        return sum;
    }
};
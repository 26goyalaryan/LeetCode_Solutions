class Solution {
    /*
        the logic is simple mathematics, 
        we must increment the smaller element everytime bcz it increases the value by
        more % .
        eg: [1,100] k=1
        
        1+1=2;2*100 = 200.
        1*(100+1)=101;
        
    */
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        // pushing elements in queue
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        // incrementing smallest element k times.
        while(k--){
            int top=pq.top();
            pq.pop();
            top+=1;
            pq.push(top);
        }
        long long ans=1;
        long long mod=pow(10,9)+7;
        // generating product
        while(pq.size()){
            long long x=pq.top();
            ans=(ans*x)%mod;
            pq.pop();
        }
        
        return ans;
    }
};
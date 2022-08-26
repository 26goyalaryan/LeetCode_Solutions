class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1,0);
        
        for(int i=0;i<=n;i++){
            int count=0;
            int num=i;
            
            while(num){
                
                count+=num%2;
                
                num=num/2; // decimal to binary, we keep dividing the no.
            }
            ans[i] = count;
        }
        return ans;
    }
};
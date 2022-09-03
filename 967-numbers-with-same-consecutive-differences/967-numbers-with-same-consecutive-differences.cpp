class Solution {
public:
    vector<int> ans;
    
    int digcount(int n){
        int count=0;
        while(n){
            count++;
            n/=10;
        }
        return count;
    }
    
    void helper(int num,int k,int n){
        if(digcount(num)==n)
        {
            ans.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++){
            int unit_dig = num%10;
            if(abs(i-unit_dig)==k)
            {
                int number = num*10+i;
                helper(number,k,n);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            helper(i,k,n);
        }
        return ans;
    }
};
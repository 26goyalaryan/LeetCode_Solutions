class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        
        int p2=0,p3=0,p5=0;
        
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            int two=dp[p2]*2;
            int three=dp[p3]*3;
            int five=dp[p5]*5;
            
            dp[i]=min(two,min(three,five));
            
            // here we are not using else statement bcz if have value like 6
            // then we will increment both p2,p3 inorder to avoid duplicates in dp
            if(dp[i]==two)
                p2++;
            if(dp[i]==three)
                p3++;
            if(dp[i]==five)
                p5++;
            
        }
        
        return dp[n-1];
    }
};
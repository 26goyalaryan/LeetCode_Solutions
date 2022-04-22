class Solution {
public:
    double myPow(double x, int n) {
        /*
            if n is even then we can reduce x^n to (x*x)^n/2;
            if n is odd then ---> ans=ans*x; n=n-1;
        */
        long long temp=n;
        double ans=1.0;
        if(temp<0)
            temp=-1*temp; 
        // making the n positive for next step
        while(temp){
            if(temp%2){
                ans=ans*x;
                temp-=1;
            }else{
                x*=x;
                temp/=2;
            }
        }
        // if n<0 then return 1/ans
        // the ans is converted to double bcz the range of int is
        // -2147483648 --> -2147483647 
        // so the last -ve can't be converted to +ve.
        if(n<0)
            ans=double(1)/double(ans);
        return ans;
    }
};
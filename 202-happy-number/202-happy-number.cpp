class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> tmp;
        while(n != 1)
        {
            if(tmp[n] == 0)
                tmp[n]++;
            else
                return false; // ie there is a cycle .
            int sum = 0;
            while(n != 0)
            {
                sum=sum+((n%10)*(n%10));
                n=n/10;
            }
            n = sum;
        }
        return true;
    }
};
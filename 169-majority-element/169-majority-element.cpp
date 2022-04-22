class Solution {
public:
    int majorityElement(vector<int>& n) {
        /* the program uses moore's voting algorithm which states that
            if at any given index, the count becomes 0, 
            then majority and minority element will be equal till that.
        */
        int cnt=0;
        int ans=n[0];
        for(int num:n){
            if(cnt==0)
                ans=num;
            if(num==ans)
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        int n=boxes.size();
        //int curr_sum=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                int curr_sum=0;
                if(boxes[j]=='1')
                {
                    curr_sum+=abs(i-j);
                    ans[i]+=curr_sum;
                }
            }
            //ans.push_back(curr_sum);
        }
        return ans;
    }
};
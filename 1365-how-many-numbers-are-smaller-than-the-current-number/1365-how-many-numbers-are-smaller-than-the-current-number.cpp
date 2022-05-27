class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        /*
        for(int i=0;i<nums.size();i++){
            int temp=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]>nums[j])
                    temp++;
            }
            ans.push_back(temp);
        }
        */
        int temp[101]={0};
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }
        for(int i=1;i<101;i++){
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                ans.push_back(0);
            else
                // push the i-1)th element bcz the no. of smaller eleements present 
                ans.push_back(temp[nums[i]-1]);
        }
        return ans;
    }
};
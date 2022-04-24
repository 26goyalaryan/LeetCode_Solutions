class Solution {
    /*
        i and j 2 pointers placednext to each other on distinct values
        left and right mark the 2 ends after j in sorted right half.
        
        if nums[i]+nums[j]+nums[left]+nums[right]==target 
            push in ans array
        if target-(nums[i]+nums[j])>nums[leftyy]+nnums[right]
            right--;
        else 
            left++;
            
            bcz if we need greater then we need to move to right
            and if smaller then to left/.
            
            time complexity--> O(n)*O(n) for 2 nested loops
            and another O(n) for the left --> right movement.
    */
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                int target_2=target-nums[i]-nums[j];
                int left=j+1;
                int right=n-1;
                while(left<right){
                    int two_sum=nums[left]+nums[right];
                    if(two_sum<target_2)
                        left++;
                    // move left-->right if need greater element
                    else if(two_sum>target_2)
                        right--;
                    else{
                        vector<int> temp(4,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        ans.push_back(temp);
                        
                        // skipping duplicates
                        while(left<right && nums[left]==temp[2]) 
                            left++;
                        while(left<right && nums[right]==temp[3])
                            right--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j])
                    j++;
            }
            while(i+1<n && nums[i+1]==nums[i])
                    i++;
        }
        return ans;
    }
};
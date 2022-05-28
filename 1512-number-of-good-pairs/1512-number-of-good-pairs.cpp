class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       int counter = 0;
        /*
        
	    for(int i=0;i<nums.size()-1;++i)
	        for(int j=i+1;j<nums.size();++j)
		        if(nums[i]==nums[j]) 
                    counter++;
        */
        int temp[101]={0};
        for(auto it:nums){
            temp[it]++;
        }
        // count the frequency of the no. present
        for(auto it:temp){
        // the no. of pairs we can make using n items it (n*(n-1))/2;
            counter+=(it*(it-1))/2;
        }
        return counter;
    }
};
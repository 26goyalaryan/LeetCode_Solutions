class Solution {
    /*
    step1: we will try to find the minimum element's index in rotated array.
    step2: apply binary search to both the left and right sorted part.
    step3: return the one whic is not -1 or -1 if both -1;
    
    eg          11 12 15 18    2   3 4 5 6 
                <--------->        <------> 
                both are sorted.
    */
private:
    int binarySearch(vector<int>& nums, int target,int lo,int hi){
        int low=lo,high=hi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                high=mid-1;
            else 
                low=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int minindex;
        int low=0,high=nums.size()-1;
        int n=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low] <= nums[high])
            {
                minindex=low;
                break;
            }
            int next=(mid+1)%n;
            // %n bcz it is a rotated array so that if mid==n then n%n =0 and again it                   // reach to the first element
            int prev=(mid+n-1)%n;
            // (mid+n-1) bcz it is roated array and if mid==0 then (-1%n) will be error.
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                minindex=mid;
                break;
            }
            else if(nums[low]<=nums[mid])
                low=mid+1;
            else if(nums[mid]<=nums[high])
                high=mid-1;
        }
        if(nums[minindex]==target)
            return minindex;
        
        int left=binarySearch(nums,target,0,minindex);
        int right=binarySearch(nums,target,minindex,n-1);
        cout<<left<<" "<<right;
        if(right==-1)
            return left;
        else
            return right;
    }
};
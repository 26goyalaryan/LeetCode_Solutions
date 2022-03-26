class Solution {
/*
    [3,4,5,1,2] the rotated array was initially as [1,2,3,4,5]
     0 1 2 3 4                                      0 1 2 3 4
     
     ie the no. of rotations == index of minimum element in rotated array.
     
     we need-
     1. if the element is minimum or not
     2. deciding factor whicj helps to choose right or left side.
     
     if we notice that the all the elements are in sorted order, except the minimum
     one as it is smaller than both its prev and next elements
     
     eg {3,4,5, 1, 2}
          <----    ->  so we just have to check that 
          nums[mid] < nums[prev] && nums[mid]<nums[next];
          and if found return else return -1
                     | 
    eg2:   11 12 15  18  2 5 6 8
                     | 
   (11--->15) sorted | unsorted (18--->8)       
          
          and if observe the minimum element is always found in unsorted part.
          so now we have both the factors.
          
          1. minimum element is always smaller than both its neighbours
          2. we gave to search further in unsorted array.

*/
    
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low] <= nums[high])
            {
                return nums[low];
            }
            int next=(mid+1)%n;
            // %n bcz it is a rotated array so that if mid==n then n%n =0 and again it                   // reach to the first element
            int prev=(mid+n-1)%n;
            // (mid+n-1) bcz it is roated array and if mid==0 then (-1%n) will be error.
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return nums[mid];
            else if(nums[low]<=nums[mid])
                low=mid+1;
            else if(nums[mid]<=nums[high])
                high=mid-1;
        }
        return -1;
    }
};
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2;
        // l=1 and r=n-2 bcz last and first element can never be a peak element
        // it must exist b/w l and r.
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
                // peak element must be greater than both of its neighbours
                return mid;
            else if(arr[mid-1]<arr[mid])
                // we always have to move to greater side bcz
                // peak element must be greater than the current one.
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};
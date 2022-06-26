class Solution {
    /*
        Consider that each local maximum is one valid peak.
        
        solution is to find one local maximum with binary search.
        
        Binary search satisfies the O(logn) computational complexity.
    */
public:
    int findPeakElement(vector<int>& num) {
        
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};
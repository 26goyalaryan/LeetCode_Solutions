class Solution {
public:
    bool isPerfectSquare(int num) {
      long int low=0,high=num;
        long int mid;
        if(num==1) return true;
        while(low<=high){
            mid=(high-low)/2 + low; // find middle element
            if(mid*mid==num)
                return true; // if num is square of mid, return true.
            if(mid*mid<num) // else update low and high using binary search
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};
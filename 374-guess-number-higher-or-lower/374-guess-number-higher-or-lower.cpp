/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        while(true){
            int mid=(high-low)/2+low; // middle element in binary search.
            int ans=guess(mid); 
            if(ans==0)
                return mid; // if middle is ans, return.
            else if(ans==-1) // else if value guessed is higher, high become mid-1;
                high=mid-1;
            else if(ans==1) // else low become mid+1.
                low=mid+1;
        }
    }
};
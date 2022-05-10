class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res=letters[0];
        int low=0;
        int high=letters.size();
        while(low<=high){
            int mid=(high+low)/2;
            if(letters[mid]==target)
                low=mid+1;
            else if(letters[mid]<target)
            {
                low=mid+1;
            }
            else{
                res=letters[mid];
                high=mid-1;
            }
        }
        return res!=letters[0]?res:letters[0];
    }
};
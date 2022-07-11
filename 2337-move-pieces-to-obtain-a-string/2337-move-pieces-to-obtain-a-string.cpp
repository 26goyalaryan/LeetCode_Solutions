class Solution {
    
    // this question is about first appearance according to target 
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        int n=target.size();
        while(i<n || j<n){
            
            // ignore _ 
            while(i<n && target[i]=='_')
                i++;
            while(j<n && start[j]=='_')
                j++;
            
            // if last index for any pointer
            // then both must be at last
            
            if(i==n || j==n)
                return i==n && j==n;
            
            // since we have ignored _ , 
            // the letter other then _ appearance of L & R must be same
            
            if(target[i]!=start[j])
                return false;
            
            if(target[i]=='L'){
                if(j<i)
                    return false;
                // bcz for L to move left, j >= i must be true
            }else{
                if(i<j)
                    return false;
                // in order for R to move right, i>=j
            }
            i++;
            j++;
        }
        return true;
    }
};
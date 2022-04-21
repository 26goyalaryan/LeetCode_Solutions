class Solution {
    /* the intution behind the solution is simple 
        1. transpose the matrix as we see there is reversal of something.
        2. reverse every row.
        
        1 2 3       1 4 7      7 4 1
        4 5 6 --->  2 5 8 ---> 8 5 2
        7 8 9       3 6 9      9 6 3
        
    */
    
    
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        // transposing matrix ie the element at [i][j] <---> [j][i]
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        // reversing evey row
        for(int i=0;i<n;i++)
            reverse(m[i].begin(),m[i].end());
    }
};
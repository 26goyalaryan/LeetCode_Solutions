class Solution {
private:
    bool bs(int low,int high,int target,vector<int> &n){
        while(low<=high){
            int mid=(high+low)/2;
            if(target==n[mid])
                return true;
            else if(target>n[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
}
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        bool temp;
        for(int i=0;i<m.size();i++){
            if(m[i][0]<=target && target<=m[i][m[0].size()-1]){
                temp=bs(0,m[0].size(),target,m[i]);
                break;
            }
        }
        return temp;
    }
};
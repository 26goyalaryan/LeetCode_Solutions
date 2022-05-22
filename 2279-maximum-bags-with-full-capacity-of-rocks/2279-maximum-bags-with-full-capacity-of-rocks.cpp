class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        vector<int> t;
        for(int i=0;i<capacity.size();i++){
            t.push_back(capacity[i]-rocks[i]);
        }
        sort(t.begin(),t.end());
        int count=0;
        for(auto it:t){
            if(it==0)
                count++;
            else{
                if(ar>=it){
                    ar-=it;
                    count++;
                }
                else
                    break;
            } 
        }
        return count;
    }
};
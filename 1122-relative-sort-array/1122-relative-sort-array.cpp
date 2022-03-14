class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // count the freq of elements in arr1
        unordered_map<int,int> mp;
        for(auto it:arr1){
            mp[it]++;
        }
        
        vector<int> ans;
        //push element from arr1 to ans similar to arr2.
        // till the freq becomes zero.
        for(auto it:arr2){
            if(mp[it]>0){
                while(mp[it]){
                    //cout<<mp[it]<<" "<<it<<endl;
                    ans.push_back(it);
                    mp[it]--;
                }
            }
        }
        int size=ans.size();
        //push rest of the elements which are not in arr2.
        for(auto it:mp){
            if(it.second>0){
                while(it.second--)
                    ans.push_back(it.first);
            }
        }
        // partially sort the array from size to end
        sort(ans.begin()+size,ans.end());
        return ans;
    }
};
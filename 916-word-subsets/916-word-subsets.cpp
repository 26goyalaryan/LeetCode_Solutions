class Solution {
    vector<int> givefreq(string s){
        vector<int> freq(26,0);
        for(auto it:s)
            freq[it-'a']++;
        return freq;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> max_freq_w2(26,0);
        // calculating the max freq of any char in strings of w2
        for(auto it:words2){
            vector<int> curr_freq=givefreq(it);
            for(int i=0;i<26;i++){
                max_freq_w2[i]=max(max_freq_w2[i],curr_freq[i]);
            }
        }
        for(auto it:words1){
            vector<int> curr_freq_w1=givefreq(it);
            bool flag=true;
            for(int i=0;i<26;i++){
                
       // checking if freq of ith char in curr string of w1 is > max_freq of that in w2
                
                if(curr_freq_w1[i]<max_freq_w2[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(it);
        }
        return ans;
        // TC- O(m+n);
    }
};
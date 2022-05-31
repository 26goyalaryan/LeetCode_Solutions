class Solution {
    /*
        we can mark the freq of char in both the strings that are being compared.
        everytime we take the OR of state with itself so new state gets updated
        
        and we update the state using left shift operator
        
        eg: abc
        000......1 1 1 
        
         [1<<char-'a'] left shift the state by corresponding index
         
         and if && of both the states is 0 ie no common char. we calculate product
    */
public:
    int maxProduct(vector<string>& words) {
        vector<int> state(words.size());
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(auto it:words[i]){
                state[i] |= 1<<(it-'a'); 
                // updating the state while traversing
            }
            // traversing from 0--->i
            for(int j=0;j<i;j++){
                if(!(state[i] & state[j])){
                    
                    // & operater takes 2 inputs and return 1 if both are 1
                    
                    if(ans<words[i].size()*words[j].size())
                        ans=(words[i].size())*(words[j].size());
                }
            }
        }
        return ans;
    }
};
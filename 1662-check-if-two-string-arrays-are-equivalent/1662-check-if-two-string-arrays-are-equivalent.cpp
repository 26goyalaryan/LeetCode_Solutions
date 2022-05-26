class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1="";
        for(auto it:word1){
            temp1+=it;
        }
        string temp2="";
        for(auto it:word2){
            temp2+=it;
        }
        return temp1==temp2;
    }
};
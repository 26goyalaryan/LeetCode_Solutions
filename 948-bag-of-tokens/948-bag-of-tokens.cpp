class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        // sort in asc order in order to reduce minimum power and maximise score
        // and if power is to be added... it must be the greatest value not consumed before
        
        sort(tokens.begin(),tokens.end());
        
        int i=0,j=tokens.size()-1;
        
        int ans=0,temp=0;
        
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                temp++;
                ans=max(ans,temp);
            }else if(temp>0){
                power+=tokens[j];
                j--;
                temp--;
            }else{
                break;
                // if power is not enough to increase the score and score isnt enough to inc power
            }
        }
        return ans;
    }
};
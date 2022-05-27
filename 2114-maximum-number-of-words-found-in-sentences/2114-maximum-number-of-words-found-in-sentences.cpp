class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int temp=1;
            // if single word that is zero space
            int k=s[i].size();
            for(int j=0;j<k;j++)
            {
                if(s[i][j]==' ')
                    temp++;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
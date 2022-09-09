class Solution {
public:
    bool static sorted(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int ans=0;
        int maxdef=INT_MIN;
        sort(p.begin(),p.end(),sorted);
        
        for(int i=p.size()-1;i>=0;i--){
            if(p[i][1]<maxdef)
                ans++;
            if(p[i][1]>maxdef)
                maxdef=p[i][1];
        }
        return ans;
    }
};
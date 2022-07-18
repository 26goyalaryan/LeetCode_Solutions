class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        if(n1<n2)
            return {};
        int i=0,j=0;
        vector<int> ans;
        vector<int> sf(26,0),pf(26,0);
        while(j<n2){
            sf[s[j]-'a']++;
            pf[p[j]-'a']++;
            j++;
        }
        j--;
        while(j<n1){
            if(sf==pf)
                ans.push_back(i);
            j++;
            if(j!=n1)
            {
            sf[s[j]-'a']++;
            //pf[p[j]-'a']++;
            sf[s[i]-'a']--;
            //pf[p[i]-'a']++;
            i++;
            }
        }
        return ans;
    }
};
class Solution {
    
    // map for memoisation
    // it reduces TC --> O(m*n) bcz only that no. of unique key's we can have
    // recursive solution leads to 2^(m*n) bcz 
    
    // total elements --> m*n;
    // each elements has choice of 2, either s1 or s2
        
    unordered_map<string,bool> mp;
    
private:
    bool helper(string s1,string s2,string s3,int l1,int l2,int l3,int p1,int p2,int p3){
        if(p3==l3)
            return (p1==l1 && p2==l2)? true:false;
        string key=to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        /*
                p1 + p2 + p3 cant be a key bcz 11+2+3 & 1+12+3 will both result to 1123 string
                so we insert the * .
        */
        if(mp.find(key)!=mp.end())
            // memoisation using map
            return mp[key];
        
        // we have reached at end of string 1 then only s2 we can check
        if(p1==l1){
            return mp[key] = s2[p2]==s3[p3]? helper(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1): false;
        }
        
         // we have reached at end of string 2 then only s1 we can check
        if(p2==l2){
            return mp[key] = s1[p1]==s3[p3]? helper(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1): false;
        }
        
        
        bool first_string=false,sec_string=false;
        
        // every char in s3 have two choices at either it belong to s1 or s2 so checking both
        
        if(s1[p1]==s3[p3])
            first_string=helper(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        
        if(s2[p2]==s3[p3])
            sec_string=helper(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        
        return mp[key]=(first_string || sec_string);
    }
public:
        bool isInterleave(string s1, string s2, string s3) {
            int len1=s1.size();
            int len2=s2.size();
            int len3=s3.size();
            if(len1+len2!=len3)
                return false;
            return helper(s1,s2,s3,len1,len2,len3,0,0,0); 
    }
};

/*

    REcursive solution
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1 + n2 != n3) return false;
        return Helper(s1, 0, n1, s2, 0, n2, s3, 0, n3);
    }
    
    bool Helper(string &s1,int i1,int n1,string &s2,int i2,int n2,string &s3,int i3,int n3){
        if(i1 == n1 && i2 == n2 && i3 == n3) return true;
        
        // fist call is for s1 ie left sutree is for s1 and right for s2
        if(i1 < n1 && s1[i1] == s3[i3] && 
           Helper(s1, i1 + 1, n1, s2, i2, n2, s3, i3 + 1, n3)) return true;
        
        if(i2 < n2 && s2[i2] == s3[i3] && 
           Helper(s1, i1, n1, s2, i2 + 1, n2, s3, i3 + 1, n3)) return true;
        
        else return false;

*/
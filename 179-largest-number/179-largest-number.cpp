class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        
        // pushing the int in form of string
        for(auto i:num)
            arr.push_back(to_string(i));
        
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        // sorting using comparator function , if s1+s2 is greater, place it earliear
        
        string res;
        for(auto s:arr)
            res+=s;
        
        // removing leading zeros of there
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
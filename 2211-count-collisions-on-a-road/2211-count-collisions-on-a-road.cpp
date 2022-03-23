class Solution {
public:
    int countCollisions(string s){
        vector<pair<char,int>> v;
        for(int i=0;i<s.size();i++){
            int c=1;
            while(i<s.size()-1 && s[i]==s[i+1])
                i++,c++;
            v.push_back({s[i],c});
            // this will store the continous presence of R||L||S
        }
        int ans=0;
        /*
        LLLSRRR
        2 leftmost L's will collide wiht L&S and 3 R's will collide to that collided
        
        case1: (i)th car to right ---> and (i+1)th car to left <-----
        case2: (i)th car to right ---> and (i+1)th stationary car ||
        case3: (i)th car statonary || and (i+1)th car <----- left
        
        
        */
        for(int i=0;i<v.size()-1;i++){
            if(v[i].first=='R' && v[i+1].first=='L')
                ans+=v[i].second+v[i+1].second;
            else if(v[i].first=='S' && v[i+1].first=='L')
                ans+=v[i+1].second;
            else if(v[i].first=='R' && v[i+1].first=='S')
                ans+=v[i].second;
        }
        return ans;
    }
};
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        // this problem is a computational problem in which we just need to find the
        // max gap b/w both horizontal and vertical cuts.
        
        sort(hc.begin(),hc.end());
        int max_h=max(hc[0],h-hc[hc.size()-1]); // including the last cut horizontally
        for(int i=1;i<hc.size();i++){
            max_h=max(max_h,hc[i]-hc[i-1]);
        }
        sort(vc.begin(),vc.end());
        int max_v=max(vc[0],w-vc[vc.size()-1]); // including the last cut vertically
        for(int i=1;i<vc.size();i++){
            max_v=max(max_v,vc[i]-vc[i-1]);
        }
        return ((long)max_v*(long)max_h)%1000000007;
    }
};
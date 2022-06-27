class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int len=flowerbed.size();
        for(int i=0;i<len;i++){
            if(flowerbed[i]==0){
                int prev=(i==0 || flowerbed[i-1]==0)?0:1;
                int next=(i==len-1 || flowerbed[i+1]==0)?0:1;
                
                if(prev==0 && next==0){
                    count++;
                    flowerbed[i]=1;
                }
            }
        }
        return count>=n;
    }
};
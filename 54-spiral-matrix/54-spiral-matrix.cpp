class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mx) {
        int dir=0;
        int left=0,top=0,right=mx[0].size()-1,down=mx.size()-1;
        vector<int> ans;
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(mx[top][i]);
                }
                dir=1;
                top+=1;
            }
            else if(dir==1){
                for(int i=top;i<=down;i++){
                    ans.push_back(mx[i][right]);
                }
                dir=2;
                right-=1;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(mx[down][i]);
                }
                dir=3;
                down-=1;
            }
            else if(dir==3){
                for(int i=down;i>=top;i--){
                    ans.push_back(mx[i][left]);
                }
                dir=0;
                left+=1;
            }
        }
        return ans;
    }
};
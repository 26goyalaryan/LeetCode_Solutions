class Solution {
private:
    void reverse(vector<int> &s){
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[0].size();j++){
                image[i][j]=!image[i][j];
            }
        }
        for(int i=0;i<image.size();i++){
            int l=0,k=image[0].size()-1;
            while(l<k){
                swap(image[i][l],image[i][k]);
                l++;k--;
            }
        }
        return image;
    }
};
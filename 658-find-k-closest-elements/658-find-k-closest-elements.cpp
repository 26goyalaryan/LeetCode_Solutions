class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int lo = 0, hi = arr.size()-k;
        while (lo < hi){
            
            int mid = lo + (hi - lo)/2;
            
            // sliding window of k size
            // if mid is starting point, then what we need is to minimise the difference b/w 
            // x - arr[mid] || arr[mid+k]-x 
            
            if(x - arr[mid] > arr[mid + k] - x){
                lo = mid + 1;
            }else{
                hi = mid;
            }
            
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[lo+i]);
        }
        
        return ans;
        
        /*
        int i=0,j=arr.size()-1;
        
        while(j-i+1>k){
            if(x-arr[i]>arr[j]-x)
                i++;
            else 
                j--;
        }
        return vector<int>(arr.begin()+i,arr.begin()+j+1);
        */
    }
};
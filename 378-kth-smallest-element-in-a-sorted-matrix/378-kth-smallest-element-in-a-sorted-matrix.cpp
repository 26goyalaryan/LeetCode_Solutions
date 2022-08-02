class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:matrix){
            for(auto j:i){
                pq.push(j);
            }
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
   /*    
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1] + 1, mid, count, tmp;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2, tmp = n - 1, count = 0;
            
			// For each row, we count the elements that are smaller then mid
            for (int i = 0; i < n; i++) {
                while (tmp >= 0 && matrix[i][tmp] > mid) 
                    tmp--;
                count += tmp + 1;
            }
            
            if (count < k) 
                lo = mid + 1;
            else 
                hi = mid;
        }
        
        return lo;
        */
    }
};
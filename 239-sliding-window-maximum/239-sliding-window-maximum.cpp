class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        vector<int> ans;
        
        // sliding window of indices bcz later we have to check for k elements only
        
        deque<int> q(k);
        
        int i;
        
        for(i=0;i<k;i++){
            
            // creating window
            
            while(!q.empty() && arr[i]>=arr[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        
        for(i=k;i<arr.size();i++)
        {
            // pushing the ans taking front index
            ans.push_back(arr[q.front()]);
            
            // removing the indices which are not more in k length
            while(!q.empty() && q.front() <= i-k)
                q.pop_front();
            
            // removing indices from back which have less value then the curr element
            while(!q.empty() && arr[i]>=arr[q.back()])
                q.pop_back();
            
            // pushing the curr index
            q.push_back(i);
        }
        
        ans.push_back(arr[q.front()]);
        
        return ans;
    }
};
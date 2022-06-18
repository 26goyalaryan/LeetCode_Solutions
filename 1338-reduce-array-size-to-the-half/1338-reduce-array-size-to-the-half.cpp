class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        
        // to store the freq of elements in dec order (max-heap)
        priority_queue<int> pq;
        
        // count the freq of elements
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        
        // pushing freq in heap
        for(auto it:mp){
            pq.push(it.second);
        }
        int count=0;
        int target=0;
        
        // as soon as no. of poppedd elements becomes greater then n/2
        // we stop , else keep popping and increase count.
        
        while(target<arr.size()/2){
            count++;
            target+=pq.top();
            pq.pop();
        }
        return count;
    }
};
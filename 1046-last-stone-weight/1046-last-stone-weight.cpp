class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq(s.begin(),s.end());
        while(pq.size()>1){
            int t=pq.top();
            pq.pop();
            int r=pq.top();
            pq.pop();
            if(t!=r)
                pq.push(t-r);
        }
        return pq.empty()?0:pq.top();
    }
};
class Solution {
public:
    int fillCups(vector<int>& t) {
        int res=0;
        // we will only taking care of largest 2 no. from the amount
        // everytime we pick max 2 elements 
        priority_queue<int> pq;
        for(auto it:t){
            pq.push(it);
        }
        while(pq.top()!=0){
            res++;
            int m1=pq.top();
            pq.pop();
            int m2=pq.top();
            pq.pop();
            m1--;
            m2--;
            pq.push(m1);
            pq.push(m2);
        }
        return res;
    }
};
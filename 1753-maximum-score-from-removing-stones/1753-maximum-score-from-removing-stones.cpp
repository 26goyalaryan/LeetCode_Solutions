class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        priority_queue<int,vector<int>> pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int count=0;
        
        while(true){
            
            int t1=pq.top();
            pq.pop();
            
            int t2=pq.top();
            pq.pop();
            
            if(t1==0 || t2==0)
                break;
            
            count++;
            
            t1--,t2--;
            
            pq.push(t1);
            pq.push(t2);
            
        }
        return count;
    }
};
class FreqStack {
        priority_queue<pair<int,pair<int,int>>> pq;
        // max heap which will first check for maximum freq and then will check for position
        unordered_map<int,int> freq;
        // to store the frequency
        int pos=0;
public:   
    void push(int val) {
        pq.push(make_pair(freq[val]++,make_pair(pos++,val)));
    }
    
    int pop() {
        auto val=pq.top();
        pq.pop();
        int x=val.second.second;
        // will return the element 
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
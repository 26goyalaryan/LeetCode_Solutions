class Solution {
public:
    
    // comp function sorts the array on the basis of given condition
    // here we are sorting on the basis of deadline .. greater one is put at last
    bool static comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(courses.begin(),courses.end(),comp);
        if(courses.size() <= 0) return 0;
        
        priority_queue<int> q;
        // we keep inserting the current course's duration
        // if at any instance the currsum exceeds the limit,
        // we pop out the course with max duration
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        // in the end only those will be left which can be completed optimally
        return q.size();
        
    }
};
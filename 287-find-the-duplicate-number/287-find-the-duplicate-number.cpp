class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int m=n.size();
        if(m>1){
            int slow=n[0];
            int fast=n[n[0]];
            while(slow!=fast){
                slow=n[slow];
                fast=n[n[fast]];
            }
            fast=0;
            while(slow!=fast){
                slow=n[slow];
                fast=n[fast];
            }
            return slow;
        }
        return -1;
    }
};
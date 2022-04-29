/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> mp;
        ListNode* p=head;
        while(p!=NULL){
            if(mp[p])
                return true;
            mp[p]=true;
            p=p->next;
        }
        return false;
    }
};
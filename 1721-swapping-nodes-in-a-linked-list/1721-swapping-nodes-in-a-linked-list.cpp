/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p, *kth,*q;
        p=head;
        while(k>1){
            p=p->next;
            k--;
        }
        kth=p;
        q=head;
        while(p->next){
            p=p->next;
            q=q->next;
        }
        swap(q->val,kth->val);
        return head;
    }
};
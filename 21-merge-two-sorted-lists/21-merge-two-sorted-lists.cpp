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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* dummy=NULL;
        ListNode* last=NULL;
        ListNode* p=l1;
        ListNode* q=l2;
        // making the first node of the new merged list.
        if(p->val<=q->val){
            dummy=last=p;
            p=p->next;
            dummy->next=NULL;
        }else{
            dummy=last=q;
            q=q->next;
            dummy->next=NULL;
        }
        // adding smaller value to the list and updating the pointer
        while(p && q){
            if(p->val<=q->val){
                last->next=p;
                last=p;
                p=p->next;
                last->next=NULL;
            }else{
                last->next=q;
                last=q;
                q=q->next;
                last->next=NULL;
            }
        }
        // which list is left, adjusting last->next to it.
        if(p){
            last->next=p;
        }
        if(q)
            last->next=q;
        return dummy;
    }
};
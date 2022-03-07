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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* dummy=NULL;
        ListNode* last=NULL;
        ListNode* p=list1;
        ListNode* q=list2;
        if(p->val<=q->val){
            dummy=last=p;
            p=p->next;
            dummy->next=NULL;
        }
        else{
            dummy=last=q;
            q=q->next;
            dummy->next=NULL;
        }
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
        if(p){
            last->next=p;
        }
        if(q)
            last->next=q;
        return dummy;   
    }
};
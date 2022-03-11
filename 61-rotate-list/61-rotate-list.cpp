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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)
            return head;
        ListNode* p=head;
        int count=1;
        
        // step-1: count no. of nodes
        
        while(p->next){
            p=p->next;
            count++;
        }
        
        //step-2 make list circular.   
        p->next=head;
     
        // step3 adjust k such that every time k is multiple of count, we have to return the same list
        // so make it k%count so that (k/count) rotation dont take extra time.
        
        k=k%count;
        k=count-k;
        
        while(k--){
            p=p->next;
        }
        
        // step-4 break the circular list and return new head.
        
        ListNode* dummy=p->next;
        p->next=NULL;
        return dummy;
    }
};
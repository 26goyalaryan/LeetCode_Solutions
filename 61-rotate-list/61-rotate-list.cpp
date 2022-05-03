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
        int count=1;
        ListNode* p=head;
        
        // count elements and reach till last node
        while(p->next){
            p=p->next;
            count++;
        }
        
        // making list circular
        p->next=head;
        k=k%count;
        // may be k is so large, so to reduce time complexity, we take %len
        int n=count-k;
        
        // traverse till len-k nodes so as to break link and return new head 
        while(n--){
            p=p->next;
        }
        ListNode* newHead=p->next;
        p->next=NULL;
        return newHead;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        ListNode* smaller=new ListNode(-1);
        ListNode* larger=new ListNode(-1);
        smaller->next=head;
        larger->next=head;
        ListNode* smallhead=smaller;
        ListNode* largerhead=larger;
        while(head){
            if(head->val<x){
                smaller->next=head;
                smaller=smaller->next;
            }else{
                larger->next=head;
                larger=larger->next;
            }
            head=head->next;
        }
        larger->next=NULL;
        smaller->next=largerhead->next;
        return smallhead->next;
    }
};
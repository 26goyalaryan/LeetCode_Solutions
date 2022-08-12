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
        ListNode* sh=new ListNode(-1,NULL);
        ListNode* lh=new ListNode(-1,NULL);
        
        ListNode* small=sh,*large=lh;
        
        while(head){
            if(head->val<x){
                ListNode* temp=new ListNode(head->val);
                small->next=temp;
                small=small->next;
            }else{
                ListNode* temp=new ListNode(head->val);
                large->next=temp;
                large=large->next;
            }
            head=head->next;
        }
        large->next=NULL;
        small->next=lh->next;
        return sh->next;
    }
};
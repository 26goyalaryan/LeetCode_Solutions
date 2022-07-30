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
    int count(ListNode* head){
        int count=0;
        ListNode* itr=head;
        while(itr!=NULL){
           
            itr=itr->next;
            count++;
        }
        return count;
    }
public:
    ListNode* helper(ListNode* head, int k,int len) {
        if(len<k)
            return head;
        int count_chk=0;
        ListNode* prev=NULL,*next=NULL,*curr=head;
        while(count_chk<k && curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count_chk++;
        }
        if(next!=NULL)
            head->next=helper(next,k,len-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = count(head);
        return helper(head, k, length);
    }
};

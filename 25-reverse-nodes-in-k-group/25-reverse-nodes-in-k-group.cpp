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
        ListNode* it=head;
        while(it!=NULL){
           
            it=it->next;
            count++;
        }
        return count;
    }
public:
    ListNode* helper(ListNode* head, int k,int len) {
        if(len<k)
            return head;
        int cnt=0;
        ListNode* curr=head,*prev=NULL,*next=NULL;
        while(cnt<k && curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
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

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
        if(head==NULL)
            return NULL;
        int count=0;
        ListNode* p=head;
        while(p!=NULL){ // count no. of nodes
            p=p->next;
            count++;
        }
        int target=count-k; // target from end.
        int i=0;
        p=head;
        while(i<k-1){
            p=p->next; // traverse til kth node from front.
            i++;
        }
        ListNode* q=head;
        int j=0;
        while(j<target){
            q=q->next; // traverse til kth node from end or (count-k)th node from front.
            j++;
        }
        swap(p->val,q->val); // swap values.
        return head;
    }
};
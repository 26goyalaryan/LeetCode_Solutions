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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* zero=head;
        ListNode* p=head->next;
        while(p!=NULL){
            if(p->val!=0) // if not zero, keep adding value to the initial zero node.
                zero->val+=p->val;
            else{
                if(p->next==NULL)
                    zero->next=p->next; // last zero node
                else
                    zero->next=p; // else update prev zero to next zero where p is currently pointing.
                zero=p;
            }
            p=p->next; // keep updating p;
        }
        return head;
    }
};
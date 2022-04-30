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
    // reverse the linked list
private:
    ListNode* reverse(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        // find the middle of the list 
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* dummy=head;
        // revrse after middle part
        slow->next=reverse(slow->next);
        // update slow and start checking
        slow=slow->next;
        ListNode* p=head;
        while(slow!=NULL){
            if(p->val!=slow->val)
                return false;
            p=p->next;
            slow=slow->next;
        }
        return true;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* current=node;
        ListNode* succ=node->next;
        current->val=succ->val;
        current->next=succ->next;
        succ->next=NULL;
        delete succ;
    }
};
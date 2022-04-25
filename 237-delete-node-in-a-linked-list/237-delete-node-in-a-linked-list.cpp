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
        ListNode* curr=node;
        ListNode* nxt=node->next;
        curr->val=nxt->val; //updating value of next node to curr node;
        curr->next=nxt->next; // adjusting next pointer
        delete nxt; //delete the target node;
    }
};
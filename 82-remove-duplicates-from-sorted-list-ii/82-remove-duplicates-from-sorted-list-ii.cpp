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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        unordered_map<int,bool> visited; // map to check if value is duplicate or not
        ListNode* curr=head;
        ListNode* next=head->next;
        while(next!=NULL){
            if(curr->val==next->val){
                // mark the node visted
                visited[curr->val]=true;
                // delete the next node having duplicate value
                ListNode* temp=next;
                curr->next=temp->next;
                next=next->next;
                temp->next=NULL;
                delete temp;
            }
            else{
                curr=next;
                next=next->next;
            }
        }
        // now delete all the nodes having visited[val]== true;
        ListNode* prev=head;
        curr=head->next;
        while(curr){
            if(visited[curr->val]){
                ListNode* temp=curr;
                curr=curr->next;
                prev->next=curr;
                temp->next=NULL;
                delete temp;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        // check for head;
        if(visited[head->val]){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        return head; // updated head if duplicate.
    }
};
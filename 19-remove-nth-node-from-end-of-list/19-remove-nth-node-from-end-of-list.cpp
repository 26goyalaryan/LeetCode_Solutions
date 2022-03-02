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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int count=0;
        ListNode* p=head;
        while(p){
            count++;
            p=p->next;
        }
         if(count==1) 
            return NULL; // only element to be deleted.
        int target=count-n;
        ListNode* q=NULL; // tail pointer
        p=head;
        for(int i=0;i<target;i++){
            q=p;
            p=p->next;
        }
        if(n==1){ // last element to be deleted 
            q->next=NULL;
            delete p;
        }
        else if(target==0){
            head=head->next; // first node to be deleted.
            delete p;
        }
        else{
            q->next=p->next;
            p->next=NULL;
            delete p;
        }
        return head;
    }
};
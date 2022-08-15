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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return ; // bcz we need at least 3 nodes
        
        stack<ListNode*> st;
        
        ListNode* temp = head;
        int size=0;
        
        while(temp){
            
            st.push(temp);
            
            size++;
            
            temp=temp->next;
        }
        
        ListNode* curr=head;
        
        for(int j=0;j<size/2;j++) // we can put half of the nodes in b/w   
        {
            
            // pick topmost node from stack and put b/w 2 nodes
            ListNode* top = st.top();
            st.pop();
            
            top->next=curr->next;
            
            curr->next = top;
            
            curr=curr->next->next;
        }
        
        curr->next=NULL;
        
        return;
    }
};
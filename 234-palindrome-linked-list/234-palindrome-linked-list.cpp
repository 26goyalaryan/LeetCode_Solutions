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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return false;
        stack<int> st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val); // while traversing push into stack.
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL && !st.empty()){
            if(temp->val!=st.top()) 
                // if stack top is not equal to nodes val from start return false;
                return false;
            temp=temp->next;
            st.pop();
        }
        return true;
    }
};
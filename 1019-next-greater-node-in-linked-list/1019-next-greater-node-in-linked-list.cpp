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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        // stack of pair for {element,index of the element in LL}
        stack<pair<int,int>> st;
        // keep poping till next greater is found
        
        ListNode* p=head;
        for(int i=0;p;p=p->next){
            while(!st.empty() && p->val>st.top().first){
                ans[st.top().second]=p->val;
                st.pop();
            }
            // else push elements 
            st.push({p->val,i++});
            ans.push_back(0);
        }
        return ans;
    }
};
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
        vector<int> vals;
        ListNode* p=head;
        
        //traverse linked list and generate array 
        while(p!=NULL){
            vals.push_back(p->val);
            p=p->next;
        }
    
        vector<int> ans(vals.size(),0);
        
        // stack of pair for {element,index of the element in LL}
        stack<pair<int,int>> st;
        
        // keep poping till next greater is found
        for(int i=0;i<vals.size();i++){
            while(!st.empty() && vals[i]>st.top().first){
                ans[st.top().second]=vals[i];
                st.pop();
            }
            // else push elements 
            st.push({vals[i],i});
        }
        return ans;
    }
};
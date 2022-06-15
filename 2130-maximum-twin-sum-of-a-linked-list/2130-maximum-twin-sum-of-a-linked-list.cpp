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
    int pairSum(ListNode* head) {
        if(head==NULL)
            return 0;
        vector<int> temp;
        int ans=INT_MIN;
        ListNode* p=head;
        while(p!=NULL){
            temp.push_back(p->val);
            p=p->next;
        }
        int i=0,j=temp.size()-1;
        while(i<j){
            ans=max(ans,temp[i]+temp[j]);
            i++;
            j--;
        }
        return ans;
    }
};
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
        ListNode*temp = head;
        stack<int> st;
        int ans=0;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(temp!=nullptr){
            int sum = st.top() + temp->val;
            ans = max(sum,ans);
            temp = temp->next;
            st.pop();
        }
        return ans;
    }
};
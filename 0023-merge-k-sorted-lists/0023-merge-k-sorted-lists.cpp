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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store nodes
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<lists.size() ; i++){
            ListNode* temp = lists[i];
            while(temp!=nullptr){
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* ansHead = new ListNode(0);
        ListNode* current = ansHead;

        while(!pq.empty()){
            current->next = new ListNode(pq.top());
            current = current->next;
            pq.pop();
        }
        return ansHead->next;
    }
};
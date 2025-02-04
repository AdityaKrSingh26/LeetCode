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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;

        int length = 1;
        ListNode* tail = head;
        ListNode* curr = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        k = k % length;
        if(k==0)
            return head;
        k = length -k-1;
        while(k--){
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;
        return newHead;
    }
};
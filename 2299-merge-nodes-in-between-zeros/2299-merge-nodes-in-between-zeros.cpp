class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* start=head;
        while(start!=nullptr){
            ListNode* temp = start;
            int sum = 0;
            while (temp->val != 0) {
                sum += temp->val;
                temp = temp->next;
            }
            start->val = sum;
            start->next = temp->next;
            start = start->next;
        }
        return head;
    }
};
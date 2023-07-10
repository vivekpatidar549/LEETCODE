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
    ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev = NULL;
    ListNode* current = head;

    while (current != NULL) {
        if (current->val == val) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            ListNode* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

};
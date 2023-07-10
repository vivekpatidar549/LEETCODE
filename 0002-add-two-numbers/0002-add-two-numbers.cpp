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
    private :

    ListNode* add(ListNode* first, ListNode* second)
    {
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;
        int sum = 0;

        while(first != NULL || second != NULL || carry !=0){
            int val1=0;
            if(first!=NULL){
                val1= first->val;
            }
            int val2=0;
            if(second!=NULL){
                val2=second->val;
            }
            int sum=carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            if(first!=NULL) first=first->next;
            if(second!=NULL) second=second ->next;
        }

       /* while (first != NULL && second != NULL)
        {
            sum = carry + first->val + second->val;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            sum = carry + first->val;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
        }
        while (second != NULL)
        {
            sum = carry + second->val;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            second = second->next;
        }
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
        }*/
         return ansHead;
}

    void insertAtTail(ListNode*& head, ListNode*& tail, int digit)
    {
        ListNode* temp = new ListNode(digit);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // add these 2 linked list
        ListNode* ans = add(l1, l2);

        // reverse answer list
        //ans = reverse(ans);
        return ans;
    }
};
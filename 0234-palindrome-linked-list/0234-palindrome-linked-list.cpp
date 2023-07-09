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
 #include <vector>
class Solution {
    private:
    ListNode * middlepointer(ListNode* head){
        ListNode*slow = head;
        ListNode*fast= head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            // if(fast->next!=NULL){
            //     fast=fast->next;
            // }
            slow=slow->next;
            
        }
        return slow;
        
    }

    ListNode * reverse(ListNode * head){
        ListNode* current=head;
        ListNode* prev=NULL;
        while(current!=NULL){
            ListNode*store= current->next;
            current->next=prev;
            prev=current;
            current=store;
            
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {

    if(head==NULL || head->next==NULL){
        return true;
    }
    ListNode *middle= middlepointer(head);
    // reverse list after mid
    ListNode * temp=middle->next;
    middle->next=reverse(temp);
    // comparing both half
    ListNode*head1= head;
    ListNode*head2= middle->next;
    while (head2 != NULL) {
    if (head1->val == head2->val) {
        head1 = head1->next;
        head2 = head2->next;
    } else {
        return false;
    }
}

    // reverse list again
    temp=middle->next;
    middle->next=reverse(temp);
    return true;
        
    }
};
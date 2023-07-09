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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode*current = head;
        while(current!=NULL){
            if(current->next!=NULL &&(current->next->val==current->val)){
                ListNode * next_next=current->next->next;
                //ListNode * nodetodelete=current->next;
                delete (current->next);  /// delete(nodetodelete)
                current->next=next_next;

            }
            else{
                current=current->next;
            }
            
        }
        return head;
        
    }
};
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
    ListNode* solve(ListNode* list1, ListNode* list2){
        // initializing pointers
        ListNode* current1= list1;
        ListNode * currentnext= current1->next;
        ListNode * current2=list2;
        ListNode * next2=NULL;

        if(current1->next==NULL){
            current1->next=current2;
            return current1;
        }

        // traversing
        while(currentnext!=NULL && current2!=NULL){
            if(current1->val <=current2->val && current2->val <=currentnext->val){
                // create new node
                current1->next=current2;
                next2= current2->next;
                current2->next=currentnext;
                // update pointer
                current1=current2;
                current2=next2;
            }
            else{
                // current1 and current next should be increased
                current1=current1->next;
                currentnext=currentnext->next;
                // if any of list get empty than append remaining list
                if(currentnext==NULL){
                    current1->next=current2;
                    return list1;
                }
            }
        }
        return list1;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        // cheking the first element of both the list because here we wiil be placing elements of one on list in another list on their appropriate place
        if(list1->val <list2->val){
           return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }

        
    }
};
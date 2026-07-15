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

/*
solve this with slow fast method
Slow fast method: slow and fast are the pointer, first they will point to the head then we do slow = slow->next (means slow+1) and fast = fast->next (means fast+1) in odd case we have to stop this addition when fast->next is null and in even case we have to stop when fast = null. when the cases become true then the slow will be pointing to the middle of the ll
*/

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

/*
1) run a while loop till slow and fast are equal 
2) after that initialize slow to head
3) then we update slow and fast by one untill they both become equal again
4) the point where slow and fast meet is the starting point of the cycle

*/
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast=fast->next;
        }

        return slow;
    }
};
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
=>we can reverse the first k numbers and for the rest of the ll we can call the recursive function
1) check if k nodes exists in group
2) recursively call the function for the rest of the groups
3) reverse the curr group
4) 
*/

    //if ll is {1, 2, 3, 4, 5} for k=2

    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check if k nodes exist
        ListNode* temp = head;
        int count = 0; //used to check if k nodes exist

        while(temp != NULL && count < k){ 
            temp = temp->next;
            count++;
        } //this loop will end on count = 2 and temp = 3

        if(count < k){ //4 and 5 will remain unchanged
            return head;
        }

        // Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        count = 0;

        //for first iteration
        while(curr != NULL && count < k){
            next = curr->next;  //next = 2
            curr->next = prev; //righnt now prev = NULL, we point '1'(curr->next) to null
            prev = curr; //prev = 1
            curr = next; //curr = 2
            count++;
        }

        // Recursively reverse remaining groups
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
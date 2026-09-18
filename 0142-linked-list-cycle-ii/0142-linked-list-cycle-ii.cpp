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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
		ListNode* slow = head;
		bool isCycle = false;
			
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
			
		if(fast == slow){
			isCycle = true;
			break;
		}	
	}
		if(!isCycle){return NULL;}
		
		slow = head;
		
		while(fast != slow){
			fast = fast->next;
			slow = slow->next;
		}
		
		return slow;
    }
};
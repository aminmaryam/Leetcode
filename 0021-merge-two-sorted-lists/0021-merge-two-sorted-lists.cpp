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
1) to identify which node becomes the head in the merged ll, we compare the heads of both ll and the smaller one becomes the head
2) we recursively call the merge function to do this for the rest of the nodes
3) 
*/
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        //case 1
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else{
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};
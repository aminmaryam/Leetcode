/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

/*
A child can be null or can point to a node
we have to flatten this ll in such a way that every node's child is null
=> child should be included first 


*/
    Node* flatten(Node* head) {
        
        if(head == NULL){
            return head;
        }

        Node* curr = head;
        
        while(curr != NULL){
            //inside there will be 2 cases: child exists or child does not exits
            //1) if child does not exist: update curr to curr->next
            //2) child exists: call function recursivly 

            //for child exists case: check if curr->child is NULL or not

            if(curr->child != NULL){

                //part1: flatten child node
                Node* next = curr->next;
                curr->next = flatten(curr->child); // this flaten function will return the flatten ll of child pointers and the node next to curr will then point to the flattened part 
                curr->next->prev = curr;
                curr->child = NULL;
            

            //part2: find tail

            while(curr->next != NULL){
                curr = curr->next;
            }

            //part3: attach tail with next part

            if(next != NULL){
            curr->next = next;
            next->prev = curr;
            }

        }

        curr = curr->next;

    }

    return head;
}

};









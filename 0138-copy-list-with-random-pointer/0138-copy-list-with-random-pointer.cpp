/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

/*
we want to return the exact copy of the given ll with same random connections
every node has 2 pointers one points to the next node (like in a normal ll) and the second pointer points to a random node
steps:
1) ignore the random pointers and make the copy of the ll(means copy only the data) through unordered map
we use unordered map to do this m[original node] = copied node
unorder map stores:

Original List   
Address  Data
100      7
200      13
300      11

next column=> 
Copied List
Address  Data
500      7
600      13
700      11

2) copy random connections to the new ll    

3) 
*/
    Node* copyRandomList(Node* head) {
        if(head == NULL){//base case
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next; //Moves through original list.
        Node* newTemp = newHead; //Moves through copied list.
        m[head] = newHead; //stores the first node (the head)

        while(oldTemp != NULL){ //Copy all nodes and next pointers from the origral ll
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        //reset pointers after the copy process
        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL){
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }

};








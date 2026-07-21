/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/*
first parent of two nodes is LCA
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
        / \
       8   9

    LCA of 6 and 7 is 3

 conditions:
 1) if we are at 2 node in the binary tree and p=4 we found 4 now 
 => q can be in right subarray of 2
  OR
=> q can be below p. 
* in the second case return the p value

for ex: if we found p in left subtree and q is not found in right subtree that means q exists below p node. in that case dont search the remaining tree just  return p or root as the LCA

2) when we calculate rightLCA and leftLCA, there are follwing 4 cases
i) right and left LCA == NULL then return NULL
ii) right or left LCA have valid value then return valid value
iii) if right and left LCA are both not NULL then return root

*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        //left and right subtree cases
        if(leftLCA && rightLCA){
            return root;
        }
        else if(leftLCA != NULL){
            return leftLCA;
        }
        else{
            return rightLCA;
        }

    }
};
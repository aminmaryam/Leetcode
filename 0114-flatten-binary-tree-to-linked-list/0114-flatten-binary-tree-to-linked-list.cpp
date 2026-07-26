/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
/*
in ll every node's left subtree will point to null and right subtree will point to the next element in the inorder traversal
we are going to buil ll in reverse order of inorder traversal
*/
TreeNode* nextRight = NULL;

    void flatten(TreeNode* root) {

        if(root == NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
        
        
    }
};
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
preorder= [3, 9, 20, 15, 7] (root left right)
inorder = [9, 3, 15, 20, 7] (left root right)

1)we know that in preorder first if root
tree = [3]
2) in inorder the values on left of root is left subtree and on the right are right subtree
attach left subtree
 tree = [9, 3]
3) now we have to attach right subtree
tree = [9, 3, 20]
now again in order tells us that 15 is on left and 7 is on right of root 20

tree=[9, 3, 15, 20, 7]

use 2 pointer, left = 0, right = inorder.size() - 1

left will run from left to idx-1
right will run from idx-1 to right


*/

//we can search any value of inorder from function
    int search(vector<int>& inorder, int left, int right, int val){
        for(int i=left; i<=right; i++){
            if(inorder[i]==val){
                return i;
            }
        }

        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
        
        if(left>right){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

        return root;        
    } 

     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
    }

};
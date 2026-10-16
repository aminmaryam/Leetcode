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

bool isIdentical(TreeNode* root1, TreeNode *root2){
	
	if(root1 == NULL || root2 == NULL){
		return root1 == root2;
	}
	
	bool isleftsame = isIdentical(root1->left, root2->left);
	bool isrightsame = isIdentical(root1->right, root2->right);
	
	return isleftsame && isrightsame && root1->val == root2->val;
	
}

   bool isSubtree(TreeNode* root1, TreeNode* subtree){
	
    //if any of the tree becomes null
	if(root1 == NULL || subtree == NULL){
		return root1 == subtree;
	}
    
	//check if the mmain parent node matches the subtree
	if(root1->val == subtree->val && isIdentical(root1, subtree)){
		return true;
	}
	
	
	
	//check for left node
	return isSubtree(root1->left, subtree) || isSubtree(root1->right, subtree);
	
}

};
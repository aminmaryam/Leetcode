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
    
bool isSameTree(TreeNode* root1, TreeNode *root2){
	
	if(root1 == NULL || root2 == NULL){
		return root1 == root2;
	}
	
	bool isleftsame = isSameTree(root1->left, root2->left);
	bool isrightsame = isSameTree(root1->right, root2->right);
	
	return isleftsame && isrightsame && root1->val == root2->val;
	
}

};
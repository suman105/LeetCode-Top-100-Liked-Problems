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
        TreeNode* invertTree(TreeNode* root) {
            return invert(root);
        }
    
        TreeNode* invert(TreeNode* root){
            if(!root)   return NULL;
            TreeNode* leftNode = invert(root->left);
            TreeNode* rightNode = invert(root->right);
            root->right = leftNode;
            root->left = rightNode;
            return root;
        }
    };
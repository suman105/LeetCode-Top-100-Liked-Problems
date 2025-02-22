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
        int ComputeDiameter(int &diameter, TreeNode* root)
        {
            if(!root)   return 0;
            int leftTree = ComputeDiameter(diameter, root->left);
            int rightTree = ComputeDiameter(diameter, root->right);
    
            diameter = max(diameter, leftTree + rightTree);
    
            return 1 + max(leftTree, rightTree);
        }
    
        int diameterOfBinaryTree(TreeNode* root) 
        {
            int diameter=0;
            ComputeDiameter(diameter, root);
            return diameter;    
        }
    };
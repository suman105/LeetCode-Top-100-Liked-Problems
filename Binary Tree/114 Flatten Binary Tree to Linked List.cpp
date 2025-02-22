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
        // void helper(TreeNode *root, TreeNode* &temp){
        //     if(!root)   return;
        //     temp->right = new TreeNode(root->val);
        //     temp->left = NULL;
        //     helper(root->left,temp);
        //     helper(root->right,temp);
        // }
        struct TreeNode *prev=NULL;
        void flatten(TreeNode* root) 
        {
            if(!root)   return;
            flatten(root->right);
            flatten(root->left);
            root->right = prev;
            root->left = NULL;
            prev = root;
        }
    };
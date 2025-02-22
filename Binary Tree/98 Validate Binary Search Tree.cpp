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
        void helper(TreeNode* root, vector<int> &result,bool &found){
            if(!root)   return;
            helper(root->left,result,found);
            if(result.size()){
                if(result[result.size()-1] >= root->val)
                    found=false;
            }
            result.push_back(root->val);
            helper(root->right,result,found);
            
        }
        bool isValidBST(TreeNode* root) 
        {
            if(!root)   return true;
            vector<int> result;
            bool found=true;
            if(!root->left && !root->right) return true;
            helper(root,result,found);
            return found;
        }
    };
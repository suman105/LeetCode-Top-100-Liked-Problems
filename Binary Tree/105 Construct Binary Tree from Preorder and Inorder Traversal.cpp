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
        TreeNode* helper(vector<int>& preorder, int &preIndex, vector<int>& inorder, int start, int end)
        {
            if(start > end) return nullptr;
    
            int rootVal = preorder[preIndex++];
            TreeNode *root = new TreeNode(rootVal);
    
            int rootIndex = -1;
    
            for(int i=start; i<= end; i++){
                if(inorder[i] == rootVal){
                    rootIndex = i;
                    break;
                }
            }
    
            root->left = helper(preorder, preIndex, inorder, start, rootIndex-1);
            root->right = helper(preorder, preIndex, inorder, rootIndex+1, end);
    
            return root;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preIndex = 0;
            return helper(preorder, preIndex, inorder, 0, inorder.size()-1);
        }
    };
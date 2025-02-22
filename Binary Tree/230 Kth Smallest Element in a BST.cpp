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
        // void inorder(TreeNode *root, int &result, int &k)
        // {
        //     if(!root)   return;
        //     inorder(root->left,result,k);
        //     --k;
        //     if(!k)  result=root->val;
        //     inorder(root->right,result,k);
        // }
        int kthSmallest(TreeNode* root, int k) 
        {
            // int result=0;
            // inorder(root,result,k);
            // return result;
    
            stack<struct TreeNode*> st;
            while(root || !st.empty())
            {
                while(root){
                    st.push(root);
                    root = root->left;
                }
                root = st.top();
                st.pop();
                --k;
                if(k == 0)    return root->val;
                root = root->right;
            }
            return 0;
        }
    };
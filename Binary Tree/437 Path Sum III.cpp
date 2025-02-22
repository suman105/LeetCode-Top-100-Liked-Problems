class Solution {
    public:
        int countPaths(TreeNode* node, long long targetSum)
        {
            if (!node) return 0;
    
            int count = 0;
            
            if (node->val == targetSum) count++;
    
            count += countPaths(node->left, targetSum - node->val);
            count += countPaths(node->right, targetSum - node->val);
    
            return count;
        }
    
        int dfs(TreeNode* node, long long targetSum) 
        {
            if (!node) return 0;
            
            return countPaths(node, targetSum) + 
                dfs(node->left, targetSum) + 
                dfs(node->right, targetSum);
        }
    
        int pathSum(TreeNode* root, int targetSum) {
            return dfs(root, targetSum);
        }
    };
    
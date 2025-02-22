class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % 2 != 0) return false; // If sum is odd, partitioning is impossible
    
            int target = sum / 2;
            vector<bool> dp(target + 1, false);
            dp[0] = true; // Base case: Sum 0 is always achievable
    
            for (int num : nums) {
                for (int j = target; j >= num; j--) {
                    dp[j] = dp[j] || dp[j - num]; // Include or exclude current number
                }
            }
    
            return dp[target];
        }
    };
    
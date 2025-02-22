class Solution {
    public:
        void permutation(int start, vector<int> nums, vector<vector<int>> &result)
        {
            if(nums.size()==start){
                result.push_back(nums);
                return;
            }
    
            for(int i=start; i<nums.size(); i++){
                swap(nums[i],nums[start]);
                permutation(start+1, nums, result);
                swap(nums[i],nums[start]);
            }
        }
    
        vector<vector<int>> permute(vector<int>& nums) 
        {
            vector<vector<int>> result;
            permutation(0,nums,result);
            return result;    
        }
    };
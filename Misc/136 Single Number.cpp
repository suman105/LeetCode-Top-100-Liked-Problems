class Solution {
    public:
        int singleNumber(vector<int>& nums) 
        {
            int f = nums[0];
            for(int i=1;i<nums.size();i++)  f ^= nums[i];
            return f;
        }
    };
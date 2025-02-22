class Solution {
    public:
        int majorityElement(vector<int>& nums) 
        {
            int majorityElement=nums[0];
            int count=1;
            for(int i=1;i<nums.size();i++)
            {
                if(majorityElement == nums[i])  ++count;
                else    count -= 1;
                if(!count)
                {
                    count=1;
                    majorityElement=nums[i];
                }
            }   
            return majorityElement;
        }
    };
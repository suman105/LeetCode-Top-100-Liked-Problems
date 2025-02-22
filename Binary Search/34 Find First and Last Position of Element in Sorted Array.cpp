class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            vector<int> v;
            int i=0,j=nums.size()-1;
            int a=-1,b=-1;
            while(i<=j)
            {
                int m = (i+j)/2 ;
                if(nums[m]==target){
                    a=m;
                    --j;
                }
                else if(nums[m]>target) --j;
                else ++i;
            }    
            v.push_back(a);
            i=0;j=nums.size()-1;
            while(i<=j)
            {
                int m = (i+j)/2 ;
                if(nums[m]==target){
                    b=m;
                    ++i;
                }
                else if(nums[m]>target) --j;
                else ++i;
            } 
            v.push_back(b);
            return v;
        }
    };
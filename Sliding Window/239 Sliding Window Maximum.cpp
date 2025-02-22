class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            vector<int> result;
            deque<int> dq;
            int n=nums.size();
    
            for(int i=0; i<n; i++)
            {
                if(!dq.empty() && dq.front() == i-k) dq.pop_front();
    
                while(!dq.empty() && nums[i] >= nums[dq.back()])  dq.pop_back();
    
                dq.push_back(i);
    
                if(i >= k-1)   result.push_back(nums[dq.front()]);
            }
    
            return result;
        }
    };
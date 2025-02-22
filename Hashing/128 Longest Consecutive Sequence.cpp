class Solution {
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            if(!nums.size())    return 0;
            unordered_set<int> st(nums.begin(),nums.end());
            int longStreak=0;
    
            for(int num : nums)
            {
                if(st.find(num-1)==st.end()){
                    int currentStreak = 0;
                    while(st.find(num)!=st.end()){
                        st.erase(num);
                        num++;
                        currentStreak++;
                    }
                    longStreak = max(longStreak, currentStreak);
                }
            } 
            return longStreak;   
        }
    };
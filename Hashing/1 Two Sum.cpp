class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            
            unordered_set<int> t;
            for(int i=0;i<nums.size();i++)
            {
                if(t.find(target-nums[i])!=t.end()){
                    result.push_back(target-nums[i]);
                    result.push_back(i);
                }
                else    t.insert(nums[i]);
            }
    
            vector<int> temp;
    
            for(int i=0;i<nums.size();i++){
                if(nums[i]==result[0]){
                    temp.push_back(i);
                    break;
                }
            }
            temp.push_back(result[1]);
    
            return temp;
        }
    };
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> lastIndex(26, 0);
            vector<int> result;
            
            // Step 1: Store last index of each character
            for (int i = 0; i < s.size(); i++) {
                lastIndex[s[i] - 'a'] = i;
            }
    
            // Step 2: Create partitions
            int start = 0, end = 0;
            for (int i = 0; i < s.size(); i++) {
                end = max(end, lastIndex[s[i] - 'a']); // Extend partition if needed
    
                if (i == end) { // If we reach the furthest last occurrence
                    result.push_back(end - start + 1);
                    start = i + 1; // Start new partition
                }
            }
    
            return result;
        }
    };
    
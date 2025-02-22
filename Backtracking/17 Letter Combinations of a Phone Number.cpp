class Solution {
    public:
    
        void backtrack(string& digits, vector<string>& phoneMap, string& current, int index, vector<string>& result) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
    
            string letters = phoneMap[digits[index] - '2'];
            
            for (char c : letters) {
                current.push_back(c);
                backtrack(digits, phoneMap, current, index + 1, result);
                current.pop_back();
            }
        }
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) return {};
            
            vector<string> phoneMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            vector<string> result;
            string current;
            
            backtrack(digits, phoneMap, current, 0, result);
            return result;
        }
    };
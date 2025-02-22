class Solution {
    public:
        void backtrack(string& current, int open, int close, int n, vector<string>& result) {
            if (current.length() == 2 * n) {  
                result.push_back(current);  
                return;
            }
    
            if (open < n) {
                current.push_back('('); 
                backtrack(current, open + 1, close, n, result);
                current.pop_back();
            }
    
            if (close < open) {
                current.push_back(')');  
                backtrack(current, open, close + 1, n, result);
                current.pop_back();
            }
        }
    
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            string current;
            backtrack(current, 0, 0, n, result);
            return result;
        }
    };
    
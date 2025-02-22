class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            unordered_map<char, char> matching = {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };
    
            for (char c : s) {
                if (matching.count(c)) {
                    if (!stk.empty() && stk.top() == matching[c]) {
                        stk.pop();
                    } 
                    else  return false;
                } 
                else  stk.push(c);
            }
    
            return stk.empty();
        }
    };
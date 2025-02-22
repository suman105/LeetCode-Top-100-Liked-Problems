class Solution {
    public:
        int longestValidParentheses(string s) {
            stack<int> st;
            st.push(-1); // Initialize the stack with -1 to handle edge cases
            
            int maxLen = 0;
            
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    st.push(i);  // Push the index of '('
                } else {
                    st.pop();  // Pop the matching '(' index or the last unmatched ')'
                    
                    if (!st.empty()) {
                        maxLen = max(maxLen, i - st.top());  // Calculate valid substring length
                    } else {
                        st.push(i);  // Push the index of the unmatched ')'
                    }
                }
            }
            
            return maxLen;
        }
    };
    
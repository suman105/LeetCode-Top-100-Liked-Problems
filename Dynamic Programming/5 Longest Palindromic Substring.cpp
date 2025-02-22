class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.empty()) return "";
            
            int start = 0, maxLength = 1;
            
            for (int i = 0; i < s.size(); i++) {
                // Expand around the center for odd-length palindromes
                int len1 = expandAroundCenter(s, i, i);
                // Expand around the center for even-length palindromes
                int len2 = expandAroundCenter(s, i, i + 1);
                
                // Choose the longer palindrome
                int len = max(len1, len2);
                if (len > maxLength) {
                    maxLength = len;
                    start = i - (len - 1) / 2;  // Update the start index of the palindrome
                }
            }
            
            return s.substr(start, maxLength);
        }
        
        int expandAroundCenter(string& s, int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;  // Length of the palindrome
        }
    };
    
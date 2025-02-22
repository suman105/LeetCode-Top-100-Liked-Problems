class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;
            vector<string> path;
            backtrack(0, s, path, result);
            return result;
        }
    
    private:
        void backtrack(int index, string &s, vector<string> &path, vector<vector<string>> &result) {
            if (index == s.size()) {
                result.push_back(path);
                return;
            }
            
            for (int i = index; i < s.size(); i++) {
                if (isPalindrome(s, index, i)) {
                    path.push_back(s.substr(index, i - index + 1)); 
                    backtrack(i + 1, s, path, result);             
                    path.pop_back();                                
                }
            }
        }
    
        bool isPalindrome(string &s, int left, int right) {
            while (left < right) {
                if (s[left++] != s[right--]) return false;
            }
            return true;
        }
    };
    
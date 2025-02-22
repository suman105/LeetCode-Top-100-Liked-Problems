class Solution {
    public:
        string minWindow(string s, string t) {
            if (s.empty() || t.empty()) return "";
    
            unordered_map<char, int> tFreq, windowFreq;
            for (char c : t) tFreq[c]++; // Count frequency of characters in t
    
            int start = 0, end = 0, minStart = 0, minLen = INT_MAX, required = tFreq.size(), formed = 0;
    
            while (end < s.size()) {
                char c = s[end]; 
                windowFreq[c]++;
    
                if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                    formed++; // A required character is fully matched
                }
    
                // Try to shrink the window from the left
                while (formed == required) {
                    if (end - start + 1 < minLen) {
                        minLen = end - start + 1;
                        minStart = start;
                    }
    
                    char leftChar = s[start];
                    windowFreq[leftChar]--;
    
                    if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                        formed--; // A required character is no longer fully matched
                    }
    
                    start++; // Shrink the window
                }
    
                end++; // Expand the window
            }
    
            return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
        }
    };
    
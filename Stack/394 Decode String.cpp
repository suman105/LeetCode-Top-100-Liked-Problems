class Solution {
    public:
        string decodeString(string s) {
            stack<int> countStack;   
            stack<string> strStack; 
            string currentString = "";
            int num = 0;
    
            for (char c : s) {
                if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                } else if (c == '[') {
                    countStack.push(num);
                    strStack.push(currentString);
                    num = 0;
                    currentString = "";
                } else if (c == ']') {
                    int repeatCount = countStack.top(); countStack.pop();
                    string temp = strStack.top(); strStack.pop();
                    
                    while (repeatCount--) {
                        temp += currentString;
                    }
                    currentString = temp;
                } else {
                    currentString += c;
                }
            }
            return currentString;
        }
    };
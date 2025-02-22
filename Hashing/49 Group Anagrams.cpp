class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string, vector<string>> m;
    
            for(string &word : strs){
                vector<int> freq(26,0);
                for(char &c : word){
                    freq[c-'a']++;
                }
    
                string key="";
                for(int count : freq){
                    key += to_string(count)+"#";
                }
                m[key].push_back(word);
            }    
    
            vector<vector<string>> result;
    
            for(auto &entry : m)
                result.push_back(entry.second);
    
            return result;
        }
    };
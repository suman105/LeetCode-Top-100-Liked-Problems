class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            if(s.size() < p.size()) return result;
    
            vector<int> sf(26,0), pf(26,0);
            int pLen=p.size(), sLen=s.size();
    
            for(int i=0; i<pLen; i++){
                sf[s[i]-'a']++;
                pf[p[i]-'a']++;
            }
    
            if(sf == pf)    result.push_back(0);
    
            for(int i=pLen; i<sLen; i++){
                sf[s[i]-'a']++;
                sf[s[i-pLen]-'a']--;
    
                if(sf == pf)    result.push_back(i-pLen+1);
            }
    
            return result;
        }
    };
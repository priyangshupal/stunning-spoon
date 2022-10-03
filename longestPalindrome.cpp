class Solution {
public:
    string putHashes(string s) {
        string res = "$";
        for(char x: s) {
            res += '#';
            res += x;
        }
        res += '#';
        return res + '@';
    }
    string longestPalindrome(string s) {
        s = putHashes(s);
        vector<int> P(s.length());
        int C(0), R(0);
        for(int i=1; i < s.size() - 1; i++) {
            int mir = 2 * C - i;
            
            if(i < R) P[i] = min(R - i, P[mir]);
            
            while(s[i - (1 + P[i])] == s[i + (1 + P[i])]) P[i]++;
            
            if(i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        int len = *max_element(P.begin(), P.end());
        int index = max_element(P.begin(), P.end()) - P.begin();
        string res;
        for(int i=index - len; i <= index + len; i++) res += s[i];
        res.erase(remove(res.begin(), res.end(), '@'), res.end());
        res.erase(remove(res.begin(), res.end(), '#'), res.end());
        res.erase(remove(res.begin(), res.end(), '$'), res.end());
        return res;
    }
};

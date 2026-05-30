// my second solution, overly complicated and basically unreadable
// 0ms (and also beats 99.98% in memory somehow)

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        if(p.empty()) return s.empty();
        if(s.empty()) return p.find_first_not_of('*') == string::npos;

        int sIndex = 0, pIndex = 0, lastStar = -10, lastMatch; // lastStar stores the position of the lastStar, while lastMatch stores the position of the first character in s matched by exact match after lastStar (used to revert if we go inside the wrong branch)
        bool starMatch = false;
        while(sIndex < s.size() && pIndex < p.size()) {
            if(p[pIndex] == '*') { // ignore the stars, will be used to match any odd character
                starMatch = true; // next character will be the first exact match after a star, if it matches
                lastStar = pIndex++;
            }
            else if(s[sIndex] == p[pIndex] || p[pIndex] == '?') { // simple match, skip to the next character on both
                ++pIndex;
                ++sIndex;
                lastMatch = starMatch ? sIndex : lastMatch; // if starMatch is true, this is the next exact match after the last star
                starMatch = false;
            }
            else if(pIndex - 1 == lastStar) { // no exact match, if the last pattern character is a star then just skip the current string one
                ++sIndex;
            }
            else { // we went through the wrong branch, go back to the last star but consume one more character this time
                if(lastStar < 0) return false;
            
                starMatch = true;
                pIndex = lastStar + 1;
                sIndex = lastMatch;
            }
        }

        if(sIndex == s.size() && pIndex == p.size()) return true; // perfect match
        else if(sIndex == s.size()) { // if the string was completely match but the pattern was not, it is still valid if only stars remain in the pattern
            while(pIndex < p.size()) if(p[pIndex++] != '*') return false;
            return true;
        }
        else { // if the pattern was completely match but the string was not, it is still valid if we can find a star to consume more of the string
            pIndex = p.size() - 1; sIndex = s.size() - 1;
            while(pIndex >= 0 && sIndex >= 0) {
                if(p[pIndex] == '*') return true;
                else if(p[pIndex] != '?' && s[sIndex] != p[pIndex]) return false;

                --pIndex; --sIndex;
            }

            return false;
        }
    }
};


/*
// First solution I came up with, based on dynamic programming
// 48ms

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        if(p.empty()) return s.empty();
        if(s.empty()) return p.find_first_not_of('*') == string::npos;

        vector<vector<bool>> dp;
        dp.reserve(p.size());
        for(int i = 0; i < p.size(); ++i) {
            dp.push_back(vector<bool>(s.size(), false));
        }

        // fill the first row
        dp[0][0] = s[0] == p[0] || p[0] == '*' || p[0] == '?';
        for(int i = 1; i < s.size(); ++i) {
            dp[0][i] = p[0] == '*';
        }

        // fill the first column
        bool consumed = s[0] == p[0] || p[0] == '?';
        for(int i = 1; i < p.size(); ++i) {
            dp[i][0] = dp[i - 1][0] && (p[i] == '*' || ((p[i] == s[0] || p[i] == '?') && !consumed));
            consumed |= p[i] == s[0] || p[i] == '?';
        }

        // the dp process itself
        for(int i = 1; i < p.size(); ++i) {
            for(int j = 1; j < s.size(); ++j) {
                dp[i][j] = 
                    ((p[i] == s[j] || p[i] == '?') && dp[i - 1][j - 1]) ||
                    (p[i] == '*' && (dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1]));
            }
        }
        
        return dp[p.size() - 1][s.size() - 1];
    }
};
*/
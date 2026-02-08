#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string& s, string& p) {
        bool dp[21][21];
        dp[0][0] = true; // if both are empty, then they match
        // if the pattern is empty but the string isnt then they dont match
        for(int i = 1; i <= s.size(); ++i) dp[0][i] = false;
        // a non empty pattern only matches a empty string if it consists only of * pairs
        for(int i = 1; i <= p.size(); ++i) dp[i][0] = (p[i - 1] == '*' && dp[i - 2][0]);

        // the first two if statements can be joined resulting in a unreadable one liner (it is already unreadable as is)
        for(int line = 1; line <= p.size(); ++line) {
            for(int col = 1; col <= s.size(); ++col) {
                // if p is a star, then we can              match the current s to it                              or   leave it empty
                if(p[line - 1] == '*' && (((p[line - 2] == '.' || p[line - 2] == s[col - 1]) && dp[line][col - 1]) || dp[line - 2][col])) {
                    dp[line][col] = true;
                }
                // p is not a star but it matches s
                else if((p[line - 1] == '.' || p[line - 1] == s[col - 1]) && dp[line - 1][col - 1]) dp[line][col] = true;
                // p cannot match s
                else dp[line][col] = false;
            }
        }

        return dp[p.size()][s.size()];
    }
};


/*
// recursive parsing solution that explores the whole tree, not very efficient since it has exponential time complexity
class Solution {
public:
    // use global variables to minimize recursion cost
    int s_index = 0;
    int p_index = 0;
    string input = "";
    string pattern = "";

    bool parseNext() {
        // consume zero or more characters
        if(p_index + 1 < pattern.size() && pattern[p_index + 1] == '*') {
            int start_s_index = s_index;
            p_index += 2;
            if(parseNext()) return true; // consume 0
            while(s_index < input.size() && (pattern[p_index - 2] == '.' || pattern[p_index - 2] == input[s_index])) {
                ++s_index;
                if(parseNext()) return true;
            }
            s_index = start_s_index;
            p_index -= 2;
            return false;
        }

        // check if both strings are fully consumed if one of them is
        if(p_index == pattern.size() || s_index == input.size())
            return p_index == pattern.size() && s_index == input.size();

        // consume one character
        else if(pattern[p_index] == '.' || pattern[p_index] == input[s_index]) {
            ++s_index; ++p_index;
            bool res = parseNext();
            --s_index; --p_index;
            return res;
        }
        else return false; // cannot consume anything
    }

    bool isMatch(string& s, string& p) {
        input = move(s);
        pattern = move(p);
        return parseNext();
    }
};
*/
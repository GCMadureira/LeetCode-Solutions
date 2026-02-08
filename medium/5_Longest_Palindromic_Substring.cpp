// solved using DP instead of Manacher's Algorithm because that is cheating :)
// 93ms

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string& s) {
        bool dp[1000][1000];
        int left_res = 0, right_res = 0;

        // initialize all substrings with size 1
        for(int i = 0; i < s.size(); ++i) dp[i][i] = true;
        for(int i = 0; i < s.size() - 1; ++i) { // and all with size 2
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                left_res = i; right_res = i + 1;
            }
            else dp[i][i + 1] = false;
        }

        // a substring starting in i and ending in j is a palindrome if
        // the string starting in i + 1 and ending in j - 1 is also a palindrome and s[i] == s[j]
        for(int offset = 2; offset < s.size(); ++offset) {
            for(int i = 0; i < s.size() - offset; ++i) {
                int j = i + offset;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    left_res = i; right_res = j;
                }
                else dp[i][j] = false;
            }
        }

        return s.substr(left_res, right_res - left_res + 1);
    }
};
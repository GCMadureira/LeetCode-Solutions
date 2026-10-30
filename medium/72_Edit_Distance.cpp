// why did I only learn today that dynamic programming does not always need O(n²) space even though it is so obvious??
// 0ms (however, it is not cosisten, for a real 0ms solution it needs some stupid optimizations or just plain C)

#include <string>
using namespace std;

#define MIN(a,b) (a < b ? a : b)

class Solution {
public:
    int minDistance(string& word1, string& word2) {
        // filter out empty strings
        if(word1.empty() || word2.empty()) return max(word1.size(), word2.size());

        int dp[501];

        // to transform a string into nothing the size of the string operations are needed
        for(int i = 0; i <= word2.size(); ++i) {
            dp[i] = i;
        }

        int prev, temp;

        // check which of the three operations we can apply to minimize the distance, if the letters match we can also choose to do nothing
        for(int line = 1; line <= word1.size(); ++line) {
            prev = line - 1;
            dp[0] = line;
            for(int col = 1; col <= word2.size(); ++col) {
                temp = dp[col];
                dp[col] = MIN(MIN(dp[col], dp[col - 1]), prev - (word1[line - 1] == word2[col - 1] ? 1 : 0)) + 1;
                prev = temp;
            }
        }

        return dp[word2.size()];
    }
};

/*
// dynamic programming solution, works but does not quite reach 0ms
// 8ms
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string& word1, string& word2) {
        // filter out empty strings
        if(word1.empty() || word2.empty()) return max(word1.size(), word2.size());

        vector<vector<int>> dp(word1.size(), vector(word2.size(), 0));
        dp[0][0] = !(word1[0] == word2[0]);

        // initialize the matrix, only if the letters of the two words match, and only the first time, is not operation needed
        bool matched = word1[0] == word2[0];
        for(int i = 1; i < word2.size(); ++i) {
            dp[0][i] = dp[0][i - 1] + (matched || word1[0] != word2[i]);
            matched = matched || word1[0] == word2[i];
        }

        matched = word1[0] == word2[0];
        for(int i = 1; i < word1.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + (matched || word1[i] != word2[0]);
            matched = matched || word1[i] == word2[0];
        }

        // check which of the three operations we can apply to minimize the distance, if the letters match we can also choose to do nothing
        for(int line = 1; line < word1.size(); ++line) {
            for(int col = 1; col < word2.size(); ++col) {
                dp[line][col] = min(min(dp[line - 1][col], dp[line][col - 1]), dp[line - 1][col - 1] - (word1[line] == word2[col] ? 1 : 0)) + 1;
            }
        }

        return dp[word1.size() - 1][word2.size() - 1];
    }
};
*/
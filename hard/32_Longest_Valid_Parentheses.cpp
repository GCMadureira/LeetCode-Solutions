// O(n) solution that validates parentheses and then counts the maximum substring of valid ones
// 0ms

#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string& s) {
        stack<int> st = stack<int>(); // to store indexes
        vector<bool> valid = vector<bool>(s.size(), false); // to mark valid parentheses
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') st.push(i);
            else if(!st.empty()) {
                valid[st.top()] = true;
                valid[i] = true;
                st.pop();
            }
        }

        int result = 0, current = 0;
        for(int i = 0; i < valid.size(); ++i) {
            if(valid[i]) ++current;
            else {
                result = max(result, current);
                current = 0;
            }
        }

        return max(result, current);
    }
};
// easy problem with a straightforward solution
// 0ms

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string& s) {
        char close[126] = {0};
        close[']'] = '[';
        close[')'] = '(';
        close['}'] = '{';

        stack<char> st = stack<char>();
        for(char c : s) {
            if(close[c] == 0) st.push(c);
            else if(!st.empty() && st.top() == close[c]) st.pop();
            else return false;
        }

        return st.empty();
    }
};
// simple linear algorithm, the result is stored negative because abs(INT_MIN) > INT_MAX (helps preventing overflow)
// 0ms

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int myAtoi(string& s) {
        int result = 0, index = 0;
        bool negative = false;

        // ignore whitespace
        while(s[index] == ' ') ++index;

        // get the sign if present or terminate if invalid string
        if(s[index] == '+' || s[index] == '-') negative = (s[index++] == '+' ? false : true);
        else if(!isDigit(s[index])) return 0;

        // get the digits
        for(; index < s.size() && isDigit(s[index]); ++index) {
            // prevent overflows
            if(result < INT_MIN/10 || (result == INT_MIN/10 && s[index] - '0' > (negative ? 8 : 7))) return (negative ? INT_MIN : INT_MAX);
            result = result*10 - (s[index] - '0');
        } 

        return result * (negative ? 1 : -1);
    }
};
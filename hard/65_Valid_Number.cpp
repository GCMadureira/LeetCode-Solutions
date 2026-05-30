// validate each character in order, something like a state machine parser but way simpler
// 0ms (and also beats 99.76% in memory apparently)

#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(const string& s) {
        int current = parseSimpleNumber(s, 0, true);
        if(current == -1) return false;

        // optional exponent part
        if(current < s.size() && (s[current] == 'e' || s[current] == 'E')) {
            ++current;

            current = parseSimpleNumber(s, current, false);
            if(current == -1) return false;
        }

        return current == s.size();
    }

    int parseSimpleNumber(const string& s, int start, bool includeDecimal) {
        int current = start;
        if(current >= s.size()) return -1;

        // the optional sign
        if(s[current] == '+' || s[current] == '-') ++current;

        // the optional integer part of the number
        while(current < s.size() && s[current] >= '0' && s[current] <= '9') ++current;

        // optional dot, and if it exists check for the optional decimal part
        if(includeDecimal && current < s.size() && s[current] == '.') {
            ++current;

            // decimal part
            while(current < s.size() && s[current] >= '0' && s[current] <= '9') ++current;

            // a single dot, not allowed
            if(current - start == 1) return -1;

            // something like -. which is also not allowed
            if(current - start == 2 && (s[start] == '+' || s[start] == '-')) return -1;
        }

        // a single sign, not allowed
        if(current - start == 1 && (s[start] == '+' || s[start] == '-')) return -1;

        return current - start == 0 ? -1 : current;
    }
};
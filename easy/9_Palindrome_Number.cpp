// solved without converting to a string
// 0ms

#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; // negative sign
        if(x/10 == 0) return true; // one digit

        x = abs(x);

        int divisor = pow(10, int(log10(x))); // helper value to get the most significant digit
        while(x/10 > 0) {
            if(x/divisor != x%10) return false;

            x = (x - (x/divisor)*divisor)/10;
            divisor /= 100;
        }

        // weird condition to cover every edge case, 10001 should be true but 10011 should not
        return x == 0 || divisor <= 1;
    }
};
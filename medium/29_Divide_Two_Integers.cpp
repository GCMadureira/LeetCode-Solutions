// Another weird overcomplicated solution
// 0ms

#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;

        //edge cases, when the arguments cannot be converted to positive
        if(divisor == 0x80000000) return dividend == divisor ? 1 : 0; //divisor is -2^31
        if(dividend == 0x80000000) { //dividend is -2^31
            if(divisor == 1) return INT_MIN;
            if(divisor == -1) return INT_MAX;

            //instead of a/b, do (a-b)/b + 1, prevents overflow
            dividend += divisor > 0 ? divisor : (divisor ^ 0xFFFFFFFF) + 1;
            res = 1;
        }

        //convert both arguments to their positive counterpart
        bool negative = false;
        if(dividend < 0) {
            dividend = (dividend ^ 0xFFFFFFFF) + 1;
            negative = !negative;
        }
        if(divisor < 0) {
            divisor = (divisor ^ 0xFFFFFFFF) + 1;
            negative = !negative;
        }

        //no point in doing the rest of the division, since it will be 0
        if(dividend < divisor) return negative ? (res ^ 0xFFFFFFFF) + 1 : res;

        //weird stuff to find how many left shifts are needed for both MSB to align
        int curMultiplier = 0;
        while(((dividend >> curMultiplier) ^ divisor) > divisor) ++curMultiplier;
        
        //remove each power of 2 decreasingly if possible
        for(; curMultiplier >= 0; --curMultiplier) {
            if(divisor << curMultiplier <= dividend) {
                res += 1 << curMultiplier;
                dividend -= divisor << curMultiplier;
            }
        }

        if(negative) res = (res ^ 0xFFFFFFFF) + 1;

        return res;
    }
};
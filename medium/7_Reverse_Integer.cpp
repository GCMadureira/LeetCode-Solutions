// weird edge cases
// 0ms

#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;

        bool negative = (x < 0);
        int result = 0;
        x = abs(x);
        while(x > 0) {
            if(result > INT_MAX/10 || (result == INT_MAX/10 && x%10 > 7)) return 0;

            result = result*10 + x%10;
            x /= 10;
        }

        return result*(negative ? -1 : 1);
    }
};
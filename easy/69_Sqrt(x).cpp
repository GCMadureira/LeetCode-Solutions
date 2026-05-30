// simples binary search solution, another option would be using x/mid instead of mid*mid to prevent overflows, though I am not sure what is better between casts and division
// 0ms

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;

        int low = 0, high = x;
        unsigned long mid;
        while(low < high - 1) {
            mid = (high - low)/2 + low;
            unsigned long mid2 = mid*mid;

            if(mid2 == x) return mid;
            else if(mid2 > x) high = mid;
            else low = mid;
        }

        return low;
    }
};
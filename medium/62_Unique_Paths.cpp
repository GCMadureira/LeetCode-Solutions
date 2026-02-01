// Standard implementation of the combinations (nCk) which prevents overflow
// 0ms

#define MIN(a, b) (a < b ? a : b)

class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long res = 1;
        unsigned long long sum = m + n - 2;
        
        for(unsigned long long i = 1; i <= MIN(m - 1, n - 1); ++i) {
            res *= sum--;
            res /= i;
        }

        return res;
    }
};
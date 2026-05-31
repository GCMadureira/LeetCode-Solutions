// recursive solution with memoization, there is probably some weird formula that calculates this in O(1) time, im sure....
// 0ms

class Solution {
public:
    int map[20];

    int numTrees(int n) {
        map[0] = 1;
        map[1] = 1;
        map[2] = 2;
        for(int i = 3; i < 20; ++i) map[i] = -1;

        return recurse(n);
    }

    int recurse(int n) {
        if(map[n] != -1) return map[n];

        int result = 0;
        for(int i = 0; i < n; ++i) {
            result += recurse(n - 1 - i) * recurse(i);
        }

        map[n] = result;
        return result;
    }
};
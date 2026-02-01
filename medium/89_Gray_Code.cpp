// I do not remember how this solution I came up with works
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    int level;
    int current;

    void combinations() {
        if(level == 0) {
            res.push_back(current);
            current = current^1;
            res.push_back(current);
            return;
        }

        --level;
        combinations();
        current = current^(1 << (level + 1));
        combinations();
        ++level;
    }

    vector<int> grayCode(int n) {
        level = 0;
        current = 0;

        combinations();

        while(level < n - 1) {
            current = current^(1 << (level + 1));
            combinations();
            ++level;
        }

        return res;
    }
};
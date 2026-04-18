// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int result = nums[0], current = 0;
        for(int n : nums) {
            current += n;
            result = result > current ? result : current;
            current = current < 0 ? 0 : current;
        }
        return result;
    }
};
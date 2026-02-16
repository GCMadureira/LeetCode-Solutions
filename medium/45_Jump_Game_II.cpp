// O(n) solution that finds the best jump in each index
// 0ms

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, remaining = 0, next = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            next = max(nums[i], next);
            if(remaining == 0) {
                ++jumps;
                remaining = next;
            }

            --remaining;
            --next;
        }
        
        return jumps;
    }
};
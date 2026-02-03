// surprisingly easy problem for a medium, standard dp algorithm
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;

        int include = 0, not_include = nums[0], current;
        for(int i = 1; i < nums.size(); ++i) {
            current = max(include + nums[i], not_include);
            include = not_include;
            not_include = current;
        }

        return not_include;
    }
};
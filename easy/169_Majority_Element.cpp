// Solved using the Boyer–Moore majority vote algorithm
// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
// 0ms

#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0, count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(count == 0) {
                result = nums[i];
                ++count;
            }
            else if(result != nums[i]) --count;
            else ++count;
        }
        return result;
    }
};
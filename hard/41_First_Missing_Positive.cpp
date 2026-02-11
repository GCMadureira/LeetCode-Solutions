// as the problem asked for, this solution has O(n) time complexity and O(1) space complexity
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // each number is checked at most twice, so this loop is O(n)
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums.size()) {
                int temp = nums[i], temp2;
                nums[i] = 0;
                while(temp > 0 && temp <= nums.size() && nums[temp - 1] != temp) {
                    temp2 = temp;
                    temp = nums[temp - 1];
                    nums[temp2 - 1] = temp2;
                }
            }
            else if(nums[i] != i + 1) nums[i] = 0;
        }

        // another O(n) loop
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1) return i + 1;
        }

        return nums.size() + 1;
    }
};
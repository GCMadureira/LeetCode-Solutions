// another O(n^2) solution
// 13ms

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int solution = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return target; // found the only solution
                else if(abs(target - sum) < abs(target - solution)) solution = sum; // update the solution if needed

                // update the lower and upper limits
                if(sum < target) {while(j < k && nums[j] == nums[j + 1]) ++j; ++j;}
                else {while(j < k && nums[k] == nums[k - 1]) --k; --k;}
            }

            while(i < nums.size() - 2 && nums[i] == nums[i + 1]) ++i;
        }

        return solution;
    }
};
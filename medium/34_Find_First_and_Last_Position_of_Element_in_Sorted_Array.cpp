// perform two binary searches to find the two limits, O(log n)
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};

        int low = 0, high = nums.size() - 1, mid, lowerLim = -1, higherLim = -1;
        if(nums[0] == target) lowerLim = 0;
        else {
            while(low <= high) {
                mid = (high - low)/2 + low;
                if(nums[mid] < target) low = mid + 1;
                else if(nums[mid] > target || (mid > 0 && nums[mid] == target && nums[mid - 1] == target)) high = mid - 1;
                else {
                    lowerLim = mid;
                    break;
                }
            }
        }

        if(lowerLim == -1) return {-1, -1};

        if(nums[nums.size() - 1] == target) return {lowerLim, int(nums.size())- 1};
        else {
            low = 0; high = nums.size() - 1;
            while(low <= high) {
                mid = (high - low)/2 + low;
                if(nums[mid] > target) high = mid - 1;
                else if(nums[mid] < target || (mid < nums.size() && nums[mid] == target && nums[mid + 1] == target)) low = mid + 1;
                else {
                    higherLim = mid;
                    break;
                }
            }
        }

        return {lowerLim, higherLim};
    }
};
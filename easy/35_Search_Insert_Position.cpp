// simple binary search
// 0ms

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high) {
            mid = (high - low)/2 + low;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return max(low, high);
    }
};
// Do 2 to 3 binary searches, still runs in O(log n)
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        //if(nums.size() == 1) return nums[0] == target ? 0 : -1;

        int cut = -2;
        if(nums[0] <= nums[nums.size() - 1]) cut = -1; //not rotated

        if(cut != -1) {
            //find the index where the array is not ordered, only if it was rotated
            int low = 0, high = nums.size() - 1, mid;
            while(high >= low) {
                mid = (high - low)/2 + low;

                if(nums[mid] == target) {
                    return mid;
                }
                
                if(mid > 0 && nums[mid] < nums[mid - 1]) {
                    cut = mid;
                    break;
                }
                else if(mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
                    cut = mid + 1;
                    break;
                }
                else if(nums[mid] < nums[0]) {
                    high = mid - 1;
                }
                else if(nums[mid] > nums[nums.size() - 1]) {
                    low = mid + 1;
                }
            }
        }

        //try to find the target in the left part
        int low = 0, high = cut == -1 ? nums.size() - 1 : cut - 1, mid;
        while(high >= low) {
            mid = (high - low)/2 + low;
            
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
        }

        //if the array was not rotated and the above binary search did not find the target, then it does not exist
        if(cut == -1) return -1;

        //try to find the target in the right part
        low = cut, high = nums.size() - 1;
        while(high >= low) {
            mid = (high - low)/2 + low;
            
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
        }

        return -1;
    }
};
// O(n^2) solution created by me before looking at the slightly better one in the comments (we ignore the ultra omega optimized version that gets 0ms)
// 121ms

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> hashmap = unordered_set<int>();
        for(int i = 0; i < nums.size(); ++i) hashmap.insert(nums[i]);

        vector<vector<int>> result = vector<vector<int>>();

        sort(nums.begin(), nums.end());
        for(int first = 0; first < nums.size() - 2; ++first) {
            for(int second = first + 1; second < nums.size() - 1; ++second) {
                int target = 0 - nums[first] - nums[second];
                // prevent repeated answers                prevent invalid answers with repeated numbers that do not exist
                if(target < nums[second] || (target == nums[second] && nums[second + 1] != nums[second]));
                else if(hashmap.contains(target)) result.push_back({nums[first], nums[second], target});

                while(second < nums.size() - 1 && nums[second] == nums[second + 1]) ++second;
            }

            while(first < nums.size() - 2 && nums[first] == nums[first + 1]) ++first;
        }

        return result;
    }
};
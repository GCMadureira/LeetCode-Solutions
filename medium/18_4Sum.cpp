// dont even feel like optimizing this, these sum problems are all the same
// 13ms

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result = vector<vector<int>>();

        sort(nums.begin(), nums.end());
        for(int i = 0; i < int(nums.size()) - 3; ++i) {
            for(int j = i + 1; j < int(nums.size()) - 2; ++j) {
                int k = j + 1;
                int l = nums.size() - 1;
                while(k < l) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if(sum == target) result.push_back({nums[i], nums[j], nums[k], nums[l]});

                    if(sum < target) {while(k < l && nums[k] == nums[k + 1]) ++k; ++k;}
                    else {while(k < l && nums[l] == nums[l - 1]) --l; --l;}
                }

                while(j < int(nums.size()) - 2 && nums[j] == nums[j + 1]) ++j;
            }

            while(i < int(nums.size()) - 3 && nums[i] == nums[i + 1]) ++i;
        }

        return result;
    }
};
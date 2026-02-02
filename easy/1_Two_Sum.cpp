#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapping;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) mapping[nums[i]] = i;
        for(int i = 0; i < nums.size(); ++i) 
            if(mapping.find(target - nums[i]) != mapping.end() && i != mapping[target - nums[i]]) {
                result.emplace_back(i);
                result.emplace_back(mapping[target - nums[i]]);
                break;
            }

        return result;
    }
};
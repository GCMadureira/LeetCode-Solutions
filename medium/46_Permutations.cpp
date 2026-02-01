// Search a tree of possible permutations of the vector selected
// 0ms

#include <vector>
using namespace std;


class Solution {
public:
    vector<bool> selected;
    vector<int> current;
    vector<vector<int>> res;
    int level;
    vector<int> nums;

    void temp() {
        if(level == nums.size() - 1) {
            res.push_back(current);
            return;
        }

        ++level;
        for(int i = 0; i < selected.size(); ++i) {
            if(selected[i] == true) continue;
            
            current[level] = nums[i];
            selected[i] = true;
            temp();
            selected[i] = false;
        }
        --level;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        selected = vector(nums.size(), false);
        current = vector(nums.size(), 0);
        level = -1;

        temp();

        return res;
    }
};
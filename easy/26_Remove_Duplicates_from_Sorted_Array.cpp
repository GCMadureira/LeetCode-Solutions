// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); ++i) {
            nums[index++] = nums[i];
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }

        return index;
    }
};
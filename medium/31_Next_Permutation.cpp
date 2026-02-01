// 0ms

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int leftCandidate = -1, rightCandidate = -1; //indexes
        auto itr = ++nums.begin(), leftItr = nums.begin();
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i - 1] < nums[i]) {
                leftCandidate = i - 1;
                rightCandidate = i;
                leftItr = itr;
            }
            else if(leftCandidate != -1 && nums[leftCandidate] < nums[i]) 
                rightCandidate = i;

            itr++;
        }

        if(leftCandidate == -1)
            std::sort(nums.begin(), nums.end());
        else {
            std::swap(nums[leftCandidate], nums[rightCandidate]);
            std::sort(leftItr, nums.end());
        }

    }
};
// simple solution using two pointers, 2 years ago when I first solved this problem it was so hard for me to do :/
// 0ms

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, solution = 0;
        while(right > left) {
            solution = max(solution, (right - left)*min(height[left], height[right]));
            if(height[left] < height[right]) ++left;
            else --right;
        }

        return solution;
    }
};
// simple solution that finds the lower container limit to calculate the water trapped
// 0ms

#include <vector>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        int leftPeaks[20000]; // will store the left upper limit of each elevation
        int peaksSize = 1; // ignore the first elevation (and by the same logic the last), they cannot trap water

        // store the left peaks values
        int currentLeftPeak = height[0];
        for(int i = 1; i < height.size(); ++i) {
            currentLeftPeak = currentLeftPeak > height[i] ? currentLeftPeak : height[i];
            leftPeaks[peaksSize++] = currentLeftPeak;
        }

        // get the min peak between the left and right and calculate the amount of water trapped
        int result = 0, currentRightPeak = height[height.size() - 1];
        for(int i = height.size() - 2; i > 0; --i) {
            currentRightPeak = currentRightPeak > height[i] ? currentRightPeak : height[i];
            int amountTrapped = (currentRightPeak < leftPeaks[i] ? currentRightPeak : leftPeaks[i]) - height[i];
            result += amountTrapped > 0 ? amountTrapped : 0;
        }

        return result;
    }
};
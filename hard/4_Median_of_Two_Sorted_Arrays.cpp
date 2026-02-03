// I could only find a O(log max(n, m) + min(n,m)) solution, this one was inspired on a comment :(
// 0ms

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArraysHelper(vector<int>& nums1, vector<int>& nums2) {
        int left_size = (nums1.size() + nums2.size())/2;
        int low = 0, high = nums1.size(), left_size1 = 0, left_size2 = left_size;
        while(low <= high) {
            left_size1 = (high - low)/2 + low;
            left_size2 = left_size - left_size1;

            if(left_size1 != 0 && left_size2 != nums2.size() && nums1[left_size1 - 1] > nums2[left_size2]) high = left_size1 - 1;     // left partition 1 is too big
            else if(left_size2 != 0 && left_size1 != nums1.size() && nums2[left_size2 - 1] > nums1[left_size1]) low = left_size1 + 1; // left partition 2 is too big 
            else break; // solution
        }

        int left_max = max(left_size1 == 0 ? INT_MIN : nums1[left_size1 - 1], left_size2 == 0 ? INT_MIN : nums2[left_size2 - 1]);
        int right_min = min(left_size1 == nums1.size() ? INT_MAX : nums1[left_size1], left_size2 == nums2.size() ? INT_MAX : nums2[left_size2]);

        return (nums1.size() + nums2.size())%2 == 0 ? (left_max + right_min)/2.0 : right_min;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) return findMedianSortedArraysHelper(nums1, nums2);
        else return findMedianSortedArraysHelper(nums2, nums1);
    }
};
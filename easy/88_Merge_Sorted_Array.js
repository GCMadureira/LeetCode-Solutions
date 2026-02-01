// In javascript because why not
// 0ms


/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */

var merge = function(nums1, m, nums2, n) {
    let ind1 = m - 1;
    let ind2 = n - 1;
    let ind = m + n - 1;

    while(ind1 >= 0 && ind2 >= 0) {
        if(nums1[ind1] > nums2[ind2]) {
            nums1[ind]= nums1[ind1];
            ind1--;
        }
        else {
            nums1[ind] = nums2[ind2];
            ind2--;
        }

        ind--;
    }

    while(ind2 >= 0) {
        nums1[ind] = nums2[ind2];
        ind2--; ind--;
    }
};
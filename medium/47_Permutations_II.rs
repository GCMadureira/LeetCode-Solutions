// explore all possible combinations avoid repeated ones early to avoid exploring useless branches
// 0ms

impl Solution {
    fn recurse(nums: &Vec<i32>, result: &mut Vec<Vec<i32>>, current_vec: &mut Vec<i32>, index: usize, used: &mut Vec<bool>) {
        // base case
        if index == current_vec.len() {
            result.push(current_vec.clone());
            return;
        }

        // iterate through all the possible candidates for the current position, ignoring already used ones
        for i in 0..nums.len() {
            // if the current candidate was already used, or the previous candidate is equal to the current one and not used (meaning the same exact number was already used in this position, so choosing it again will yield repeated combinations) skip
            if used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            current_vec[index] = nums[i];
            used[i] = true;
            Solution::recurse(nums, result, current_vec, index + 1, used);
            used[i] = false;
        }
    }

    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut max_perm = 1;
        for i in 2..=nums.len() {
            max_perm *= i;
        }

        let mut nums = nums.clone();
        nums.sort(); // crucial to avoid repeated combinations more efficiently
        let mut result = Vec::with_capacity(max_perm);
        let mut current_vec = vec![0; nums.len()];
        let mut used = vec![false; nums.len()];
        Solution::recurse(&nums, &mut result, &mut current_vec, 0, &mut used);

        result
    }
}
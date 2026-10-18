// sliding window approach
// 0ms

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut result = i32::MAX;
        let mut sum = 0;
        
        // expand to the right
        for right in 0..nums.len() {
            unsafe {
                sum += nums.get_unchecked(right);
                if sum >= target {
                    // retract from the left
                    while sum - nums.get_unchecked(left) >= target {
                        sum -= nums.get_unchecked(left);
                        left += 1;
                    }
                    
                    result = i32::min(result, (right - left) as i32 + 1);
                }
            }
        }
        
        if result != i32::MAX {result} else {0}
    }
}
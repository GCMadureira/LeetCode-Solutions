// 0ms

use std::collections::HashSet;

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut seen: HashSet<i32> = HashSet::new();
        seen.insert(n);

        let mut current = n;
        loop {
            let mut sum = 0;
            
            while current != 0 {
                let digit = current % 10;
                sum += digit * digit;
                current = current / 10;
            }

            if sum == 1 {
                return true;
            }
            else if seen.contains(&sum) {
                return false;
            }
            else {
                seen.insert(sum);
                current = sum;
            }
        }
    }
}
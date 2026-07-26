// rust types are weird
// 0ms

use std::iter::repeat_n;

impl Solution {
    fn remove_num(key: char, rest: &str, counts: &mut [usize]) -> usize {
        let c = counts[(key as u8 - b'a') as usize];

        if c == 0 {
            return 0;
        }

        for ch in rest.chars() {
            counts[(ch as u8 - b'a') as usize] -= c;
        }
        
        c
    }

    pub fn original_digits(s: String) -> String {
        let mut counts: [usize; 26] = [0; 26];
        let mut nums: [usize; 10] = [42; 10];

        for c in s.chars() {
            counts[(c as u8 - b'a') as usize] += 1;
        }

        nums[0] = Self::remove_num('z', "ero", &mut counts);
        nums[2] = Self::remove_num('w', "to", &mut counts);
        nums[6] = Self::remove_num('x', "si", &mut counts);
        nums[8] = Self::remove_num('g', "eiht", &mut counts);
        nums[3] = Self::remove_num('t', "hree", &mut counts);
        nums[4] = Self::remove_num('r', "fou", &mut counts);
        nums[5] = Self::remove_num('f', "ive", &mut counts);
        nums[1] = Self::remove_num('o', "ne", &mut counts);
        nums[7] = Self::remove_num('v', "seen", &mut counts);
        nums[9] = Self::remove_num('i', "nne", &mut counts);

        let mut capacity = 0;
        for i in nums {
            capacity += i;
        }

        let mut result = String::with_capacity(capacity);
        let mut current_char: u32 = '0' as u32;
        for i in nums {
            result.extend(repeat_n(char::from_u32(current_char).unwrap(), i));
            current_char += 1;
        }

        result
    }
}
// solution exploring the tree of possible combinations, pruning where possible
// each candidate is added as many times as possible and then removed one by one, testing all possible combinations
// 0ms (in time and memory apparently)

impl Solution {
    pub fn recurse(candidates: &Vec<i32>, target: i32, result: &mut Vec<Vec<i32>>, index: usize, current_vec: &mut Vec<i32>) {
        // a solution was found
        if target == 0 {
            result.push(current_vec.clone());
            return;
        }

        // end of the candidates vector
        if index == candidates.len() {
            return;
        }

        let num = *candidates.get(index).unwrap();
        let count = target/num; // count how many times at most we can add the current number to the solution vector

        // the numbers from now on are too large, so prune the branch
        if target < num {
            return;
        } 

        // add the number as many times as possible to the possible solution vector
        for _i in 0..count {
            current_vec.push(num);
        }

        // attempt to find a solution with the number present from the maximum number of times possible to not present at all
        for i in (1..=count).rev() {
            Self::recurse(candidates, target - num * i, result, index + 1, current_vec);
            current_vec.pop();
        }
        Self::recurse(candidates, target, result, index + 1, current_vec);
    }

    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut candidates = candidates.clone();
        candidates.sort();
        let mut current_vec = Vec::with_capacity((target / *candidates.get(0).unwrap()) as usize);

        Self::recurse(&candidates, target, &mut result, 0, &mut current_vec);

        result
    }
}

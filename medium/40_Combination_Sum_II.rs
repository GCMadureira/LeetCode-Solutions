// solution exploring the tree of possible combinations, pruning where possible
// to avoid repeating combinations, a number is only included if the previous one is different or was also included
// 0ms

impl Solution {
    pub fn recurse(candidates: &Vec<i32>, target: i32, result: &mut Vec<Vec<i32>>, index: usize, current_sum: i32, remaining_sum: i32, current_vec: &mut Vec<i32>, previous_indcluded: bool) {
        // solution found
        if current_sum == target {
            result.push(current_vec.clone());
            return;
        }

        // end of the candidates vector
        if index == candidates.len() {
            return;
        }

        // not possible to get to target in this branch, prune it
        let num = *candidates.get(index).unwrap();
        if current_sum + num > target || current_sum + remaining_sum < target {
            return;
        }

        // include the current index first (only if the number on the previous index is different or also included, else we repeat combinations)
        if previous_indcluded || num != *candidates.get(index - 1).unwrap() {
            current_vec.push(num);
            Self::recurse(candidates, target, result, index + 1, current_sum + num, remaining_sum - num, current_vec, true);
            current_vec.pop();
        }

        // then exclude it
        Self::recurse(candidates, target, result, index + 1, current_sum, remaining_sum - num, current_vec, false);
    }

    pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut current_vec = Vec::with_capacity(candidates.len());
        let total: i32 = candidates.iter().sum();
        let mut candidates = candidates.clone();
        candidates.sort();

        // not possible to get to target
        let num = *candidates.first().unwrap();
        if num > target || total < target {
            return result;
        }

        // include the current index first
        current_vec.push(num);
        Self::recurse(&candidates, target, &mut result, 1, num, total - num, &mut current_vec, true);
        current_vec.pop();

        // then exclude it
        Self::recurse(&candidates, target, &mut result, 1, 0, total - num, &mut current_vec, false);

        result
    }
}
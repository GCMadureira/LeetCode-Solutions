// 0ms

impl Solution {
    // ass solution cant think of the probably obvious better one
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec![vec![0; n as usize]; n as usize];

        let mut index: i32 = 1;
        let mut level: usize = 0;
        let n = n as usize;

        while index as usize <= n * n {
            // top line
            for i in level..n-level {
                result[level][i] = index;
                index += 1;
            }

            // right col
            for i in level+1..n-level {
                result[i][n-level-1] = index;
                index += 1;
            }

            // bottom line
            for i in (level..n-level-1).rev() {
                result[n-level-1][i] = index;
                index += 1;
            }

            // left col
            for i in (level+1..n-level-1).rev() {
                result[i][level] = index;
                index += 1;
            }

            level += 1;
        }

        result
    }
}
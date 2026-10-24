// questionable logic to solve this, but O(n) solution nonetheless
// 0ms

impl Solution {
    fn handle_slash(dot_count: usize, result: &mut String, dir_indexes: &mut Vec<usize>, last_is_slash: bool) {
        // handle the dots that may remain at the end
        if dot_count == 2 && result.len() > 1 {
            // remove the last directory only if we are not at the root
            dir_indexes.pop();
            result.truncate(dir_indexes.last().unwrap() + 1);
        } else if !(last_is_slash || dot_count == 1 || dot_count == 2) {
            // if the last character was already a slash, or if the current division is a single dot, do nothing, else add the slash
            result.push('/');
            dir_indexes.push(result.len() - 1);
        }
    }
    
    pub fn simplify_path(path: String) -> String {
        let mut result = String::with_capacity(path.len() + 1);
        let mut dir_indexes: Vec<usize> = Vec::with_capacity(path.len()/2 + 1);
        let mut last_is_slash = true;
        let mut dot_count: usize = 0;

        result.push('/');
        dir_indexes.push(0);

        for &c in path.as_bytes()[1..].iter() {
            if c == b'/' {
                // if the character is a slash, handle the end of a section
                Self::handle_slash(dot_count, &mut result, &mut dir_indexes, last_is_slash);
                last_is_slash = true;
                dot_count = 0;
            } else if (last_is_slash || dot_count > 0) && c == b'.' && dot_count < 2 {
                // if it is a dot, keep counting for the special cases /.. and /.
                dot_count += 1;
                last_is_slash = false;
            } else {
                // else, add the character like normal
                if dot_count > 0 {for _ in 0..dot_count {result.push('.')}} // fill the missing dots if needed
                result.push(c as char);
                dot_count = 0;
                last_is_slash = false;
            }
        }

        // handle the dots that may remain at the end
        Self::handle_slash(dot_count, &mut result, &mut dir_indexes, last_is_slash);

        // avoid the path ending with a slash
        if result.len() > 1 && result.as_bytes().last().unwrap() == &b'/' {
            result.pop();
        }

        result
    }
}
// first exercise solved in rust!
// 0ms

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn recurse(node: &Option<Rc<RefCell<TreeNode>>>, level: usize, result: &mut Vec<i32>)  {
        if let None = node {
            return;
        }

        if result[level] == -1000 {
            result[level] = node.as_ref().unwrap().borrow_mut().val;
        }

        Self::recurse(&node.as_ref().unwrap().borrow_mut().right, level + 1, result);
        Self::recurse(&node.as_ref().unwrap().borrow_mut().left, level + 1, result);
    }

    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result: Vec<i32> = vec![-1000; 101];

        Self::recurse(&root, 0, &mut result);

        let mut index: usize = 0;
        while result[index] != -1000 {
            index += 1;
        }

        result.truncate(index);

        result
    }
}
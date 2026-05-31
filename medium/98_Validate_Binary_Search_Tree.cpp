// use a weird pointer strategy to manage the int limits, I love C
// 0ms


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(const TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(const TreeNode* root, const int* min, const int* max) {
        // base case
        if(root == nullptr) return true;

        // verify limits of the current node
        if((min != nullptr && root->val <= *min) || (max != nullptr && root->val >= *max)) return false;
        
        // verify the child trees
        return isValidBST(root->left, min, &(root->val)) && isValidBST(root->right, &(root->val), max);
    }
};
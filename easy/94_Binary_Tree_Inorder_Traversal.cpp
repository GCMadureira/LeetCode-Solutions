// iterative solution as per the challenge, still not much harder than recursion
// 0ms

#include <vector>
using namespace std;

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
    TreeNode* stack[100];
    int size = 0;

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result = vector<int>();
        result.reserve(100);
        
        addLeftToStack(root);

        while(size > 0) {
            TreeNode* node = stack[--size];
            result.push_back(node->val);

            addLeftToStack(node->right);
        }

        return result;
    }

    void addLeftToStack(TreeNode* root) {
        while(root != nullptr) {
            stack[size++] = root;
            root = root->left;
        }
    }
};
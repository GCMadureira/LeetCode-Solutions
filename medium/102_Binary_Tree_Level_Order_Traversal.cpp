// standard BFS
// 0ms

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        vector<vector<int>> result = vector<vector<int>>();
        result.reserve(50);

        queue<TreeNode*> q = queue<TreeNode*>();
        q.push(root);

        int level = 0;
        while(!q.empty()) {
            int currentSize = q.size();
            result.emplace_back(vector<int>());
            result[level].reserve(currentSize);

            for(int i = 0; i < currentSize; ++i) {
                TreeNode* current = q.front(); q.pop();
                result[level].emplace_back(current->val);

                if(current->left != nullptr) q.push(current->left);
                if(current->right != nullptr) q.push(current->right);
            }
            
            ++level;
        }

        return result;
    }
};
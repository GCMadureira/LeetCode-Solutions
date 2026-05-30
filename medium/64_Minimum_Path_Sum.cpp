// simple dynamic programming like approach
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // init the first row each cell only has one incoming path
        for(int i = 1; i < grid[0].size(); ++i) {
            grid[0][i] += grid[0][i - 1];
        }

        // init the first column, each cell only has one incoming path
        for(int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        // calculate the rest, each cell has two incoming paths, from the top or from the left, choose the minimum cost one
        for(int row = 1; row < grid.size(); ++row) {
            for(int col = 1; col < grid[0].size(); ++col) {
                grid[row][col] += grid[row - 1][col] > grid[row][col - 1] ? grid[row][col - 1] : grid[row - 1][col];
            }
        }

        return grid[grid.size() - 1][grid[0].size()  -1];
    }
};
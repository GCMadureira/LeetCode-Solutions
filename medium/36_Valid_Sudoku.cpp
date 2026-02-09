// solution using bit manipulation because why not
// 0ms

#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for(int row = 0; row < 9; ++row) {
            for(int col = 0; col < 9; ++col) {
                if(board[row][col] == '.') continue;

                int num = board[row][col] - '0';
                if(rows[row] & (1 << num)) return false;
                else rows[row] += (1 << num);

                if(cols[col] & (1 << num)) return false;
                else cols[col] += (1 << num);
                
                int box = row/3 * 3 + col/3;
                if(boxes[box] & (1 << num)) return false;
                else boxes[box] += (1 << num);
            }
        }

        return true;
    }
};
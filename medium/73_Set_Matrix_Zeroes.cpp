// O(n * m) solution using constant space
// 0ms
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstLine = false, firstCol = false; // check if the first line and column are going to be set to 0, since later they are going to be overriden
        for(int i = 0; i < matrix.size(); ++i) firstCol |= matrix[i][0] == 0;
        for(int i = 0; i < matrix[0].size(); ++i) firstLine |= matrix[0][i] == 0;

        // use the first line and column as boolean hashmaps
        for(int row = 0; row < matrix.size(); ++row) {
            for(int col = 0; col < matrix[0].size(); ++col) {
                if(matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        // set the 0s according to the first line and column
        for(int row = 1; row < matrix.size(); ++row) {
            for(int col = 1; col < matrix[0].size(); ++col) {
                if(matrix[0][col] == 0 || matrix[row][0] == 0) matrix[row][col] = 0;
            }
        }

        // lastly complete the first line and column
        if(firstCol) for(int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        if(firstLine) for(int i = 0; i < matrix[0].size(); ++i) matrix[0][i] = 0;
    }
};
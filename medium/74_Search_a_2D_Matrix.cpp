#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1, mid = 0;
        while(low <= high) {
            mid = (high - low)/2 + low;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }

        int line = max(low > mid ? mid : high, 0);
        low = 0; high = matrix[line].size() - 1;
        while(low <= high) {
            mid = (high - low)/2 + low;
            if(matrix[line][mid] == target) return true;
            else if(matrix[line][mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
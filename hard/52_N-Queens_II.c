// try every possible combination, using maps to quickly check valid spaces; logic is the same as problem 51 but simpler
// 0ms

#include <stdlib.h>
#include <string.h>

void recurse(int* result, int row, int n, bool* cols, bool* right_diags, bool* left_diags) {
    // base case, add one to the result
    if(row == n) {
        *result += 1;
        return;
    }

    for(int col = 0; col < n; ++col) {
        // check if the (row, col) spot is available
        int right_diag_index = n - 1 - col + row;
        int left_diag_index = col + row;
        if(cols[col] || right_diags[right_diag_index] || left_diags[left_diag_index]) {
            continue;
        }

        // else, position a queen in that position
        cols[col] = true;
        right_diags[right_diag_index] = true;
        left_diags[left_diag_index] = true;
        recurse(result, row + 1, n, cols, right_diags, left_diags);

        // now remove it to prepare the next iteration
        cols[col] = false;
        right_diags[right_diag_index] = false;
        left_diags[left_diag_index] = false;
    }
}

/**
 * Same as problem 51 but simpler.
 */
int totalNQueens(int n) {
    // create 4 maps for rows, cols and the 2 diags
    bool* cols = (bool*)malloc(sizeof(bool) * n);
    bool* right_diags = (bool*)malloc(sizeof(bool) * (2*n - 1)); // n - 1 - col + row
    bool* left_diags = (bool*)malloc(sizeof(bool) * (2*n - 1)); // col + row

    // init them all to false
    for(int i = 0; i < 2*n - 1; ++i) {
        if(i < n) cols[i] = false;
        right_diags[i] = false;
        left_diags[i] = false;
    }

    // recursively position each queen row by row, marking the corresponding entries on the maps as occupied
    int result = 0;
    recurse(&result, 0, n, cols, right_diags, left_diags);

    return result;
}
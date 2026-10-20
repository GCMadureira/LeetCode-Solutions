// try every possible combination, using maps to quickly check valid spaces
// 0ms (and 99% for memory apparently)

#include <stdlib.h>
#include <string.h>

void recurse(char*** result, int* result_index, char** current, int row, int n, bool* cols, bool* right_diags, bool* left_diags) {
    // base case, add the current array to the result
    if(row == n) {
        // malloc a new array and copy the current one to it, adding to the result
        char** new_array = (char**)malloc(sizeof(char*) * n);
        for(int i = 0; i < n; ++i) {
            // same logic as the start, allocate space for a line with the null terminator and copy the existing line to it
            char* line = (char*)malloc(sizeof(char) * (n + 1));
            strcpy(line, current[i]);
            new_array[i] = line;
        }

        result[*result_index] = new_array;
        *result_index += 1;
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
        current[row][col] = 'Q';
        cols[col] = true;
        right_diags[right_diag_index] = true;
        left_diags[left_diag_index] = true;
        recurse(result, result_index, current, row + 1, n, cols, right_diags, left_diags);

        // now remove it to prepare the next iteration
        current[row][col] = '.';
        cols[col] = false;
        right_diags[right_diag_index] = false;
        left_diags[left_diag_index] = false;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
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

    // create a template blank line with no queens
    char* blank_line = (char*)malloc(sizeof(char) * (n + 1));
    blank_line[n] = '\0';
    for(int i = 0; i < n; ++i) {
        blank_line[i] = '.';
    }

    *returnSize = 0;
    char*** result = (char***)malloc(sizeof(char**) * 352); // result to be returned, 352 is the exact number of solutions for n=9
    char** current = (char**)malloc(sizeof(char*) * n); // array to be filled with each board configuration
    for(int i = 0; i < n; ++i) {
        // allocate space for a line with the null terminator and copy the blank line to it
        char* line = (char*)malloc(sizeof(char) * (n + 1));
        strcpy(line, blank_line);
        current[i] = line;
    }

    // recursively position each queen row by row, marking the corresponding entries on the maps as occupied
    recurse(result, returnSize, current, 0, n, cols, right_diags, left_diags);

    int* columnSizes = (int*)malloc(sizeof(int) * *returnSize);
    for(int i = 0; i < *returnSize; ++i) {
        columnSizes[i] = n;
    }
    *returnColumnSizes = columnSizes;

    return result;
}
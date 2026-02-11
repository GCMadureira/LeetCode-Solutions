// implemented the MRV (Minimum Remaining Values) heuristic, drastically reducing the number of explored nodes (only one that is not completely made by me)
// 3ms

#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    // to check the validity of a guess in constant time
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    vector<vector<char>> board = {};

    bool searchDFS() {
        // MRV heuristic
        int row = -1, col = -1, setBits = 0;
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if(board[r][c] == '.') {
                    int newSetBits = bitset<32>(rows[r] | cols[c] | boxes[r/3 * 3 + c/3]).count();
                    if(newSetBits > setBits) {
                        row = r;
                        col = c;
                        setBits = newSetBits;
                    }
                }
            }
        }

        // board full
        if(setBits == 0) return true;

        const int box = row/3 * 3 + col/3;
        const int valid = (rows[row] | cols[col] | boxes[box]);
        
        // try each valid number
        for(int i = 1; i <= 9; ++i) {
            if(!((valid >> i) & 1)) {
                rows[row] += (1 << i);
                cols[col] += (1 << i);
                boxes[box] += (1 << i);
                board[row][col] = i + '0';

                if(searchDFS()) return true;

                rows[row] -= (1 << i);
                cols[col] -= (1 << i);
                boxes[box] -= (1 << i);
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // build the initial board
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if(board[r][c] == '.') continue;

                int num = board[r][c] - '0';
                rows[r] += (1 << num);
                cols[c] += (1 << num);
                boxes[r/3 * 3 + c/3] += (1 << num);
            }
        }

        this->board = std::move(board);
        searchDFS();

        board = std::move(this->board);
    }
};

/*
// removed the first loop in the DFS to improve efficiency and less operations when comparing
// 39ms

class Solution {
public:
    // to check the validity of a guess in constant time
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    vector<vector<char>> board = {};
    vector<pair<int,int>> empty = {};

    bool searchDFS(int row, int col, int index) {
        // board full
        if(index == empty.size()) return true;

        const int box = row/3 * 3 + col/3;
        const int valid = (rows[row] | cols[col] | boxes[box]);
        
        // try each valid number
        for(int i = 1; i <= 9; ++i) {
            if(!((valid >> i) & 1)) {
                rows[row] += (1 << i);
                cols[col] += (1 << i);
                boxes[box] += (1 << i);
                board[row][col] = i + '0';

                if(searchDFS(empty[index + 1].first, empty[index + 1].second, index + 1)) return true;

                rows[row] -= (1 << i);
                cols[col] -= (1 << i);
                boxes[box] -= (1 << i);
                board[row][col] = '.';
            }
        }


        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        empty.reserve(81);

        // build the initial board
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if(board[r][c] == '.') {
                    empty.push_back({r, c});
                    continue;
                }

                int num = board[r][c] - '0';
                rows[r] += (1 << num);
                cols[c] += (1 << num);
                boxes[r/3 * 3 + c/3] += (1 << num);
            }
        }

        this->board = std::move(board);
        searchDFS(empty[0].first, empty[0].second, 0);

        board = std::move(this->board);
    }
};
*/

/*
// solution exploring all valid cases using DFS, BFS would probably not be a good idea since it explores too many useless options
// 47ms

class Solution {
public:
    // to check the validity of a guess in constant time
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    vector<vector<char>> board = {};

    bool searchDFS(int row, int col) {
        // search for the next free spot
        for(; row < 9; ++row) {
            for(; col < 9; ++col) {
                if(board[row][col] == '.') goto outside;
            }
            col = 0;
        }
        outside:

        // board full
        if(row == 9) return true;

        int box = row/3 * 3 + col/3;
        // try each valid number
        for(int i = 1; i <= 9; ++i) {
            if(!((rows[row] >> i) & 1) && !((cols[col] >> i) & 1) && !((boxes[box] >> i) & 1)) {
                int shift = (1 << i);
                rows[row] += shift;
                cols[col] += shift;
                boxes[box] += shift;
                board[row][col] = i + '0';

                if(searchDFS(row, col)) return true;

                rows[row] -= shift;
                cols[col] -= shift;
                boxes[box] -= shift;
                board[row][col] = '.';
            }
        }


        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // build the initial board
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if(board[r][c] == '.') continue;

                int num = board[r][c] - '0';
                rows[r] += (1 << num);
                cols[c] += (1 << num);
                boxes[r/3 * 3 + c/3] += (1 << num);
            }
        }

        this->board = std::move(board);
        searchDFS(0, 0);

        board = std::move(this->board);
    }
};
*/
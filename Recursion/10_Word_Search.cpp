#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>>& board, int row, int col, string& word, int index) {
        int n = board.size();
        int m = board[0].size();

        if(index == word.size()) return true;

        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#'; // mark visited

        // Down
        bool found = helper(board, row+1, col, word, index+1) ||
                     // Left
                     helper(board, row, col-1, word, index+1) ||
                     // Right
                     helper(board, row, col+1, word, index+1) ||
                     // Up
                     helper(board, row-1, col, word, index+1);

        board[row][col] = temp; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(helper(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCEED";
    cout << s.exist(board, word) << endl;
    return 0;
}

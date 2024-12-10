class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int row, int col,
                int m, int n, int index) {
        if (index == word.size())
            return true;
        if (row < 0 || col < 0 || row == m || col == n ||
            board[row][col] != word[index] or board[row][col] == '!')
            return false;

        char c = board[row][col];
        board[row][col] = '!';
        bool top = search(board, word, row+1, col, m, n, index+1);
        bool bottom = search(board, word, row-1, col, m, n, index+1);
        bool right = search(board, word, row, col+1, m, n, index+1);
        bool left = search(board, word, row, col-1, m, n, index+1);
        board[row][col] = c;
        return top || bottom || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (search(board, word, row, col, m, n, index))
                    return true;
            }
        }
        return false;
    }
};
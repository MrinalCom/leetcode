class Solution {
    

    bool isSafe(int row, int col, vector<string>& board, int n) {
        int i=row;
        int j=col;
        // Check row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check upper left diagonal
        i=row;
        j=col;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check bottom left diagonal
        i=row;
        j=col;
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>&ans, int n) {
        // Base case
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Recursive case
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                // Place the queen
                board[row][col] = 'Q';
                // Recurse for the next column
                solve(col+1, board, ans, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        solve(0,board,ans,n);
        return ans;
    }
};

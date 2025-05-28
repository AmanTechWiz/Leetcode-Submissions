class Solution {
private:
    vector<int> row_range = {-1, 0, 1, 0};
    vector<int> col_range = {0, 1, 0, -1};

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Traverse first and last column
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, board, visited);
            if (board[i][m - 1] == 'O' && !visited[i][m - 1])
                dfs(i, m - 1, board, visited);
        }

        // Traverse first and last row
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, board, visited);
            if (board[n - 1][j] == 'O' && !visited[n - 1][j])
                dfs(n - 1, j, board, visited);
        }

        // Replace all unvisited 'O' with 'X'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        int n = board.size();
        int m = board[0].size();
        visited[i][j] = true;

        for (int dir = 0; dir < 4; ++dir) {
            int newRow = i + row_range[dir];
            int newCol = j + col_range[dir];

            if (isValid(newRow, newCol, n, m) &&
                board[newRow][newCol] == 'O' &&
                !visited[newRow][newCol]) {
                dfs(newRow, newCol, board, visited);
            }
        }
    }

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
};

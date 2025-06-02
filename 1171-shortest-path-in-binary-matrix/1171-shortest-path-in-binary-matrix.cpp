class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        if (n == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        
        vector<int> delRow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> delCol = {-1, 0, 1, 1, 1, 0, -1, -1};

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [d, cell] = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (int i = 0; i < 8; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && d + 1 < dist[newRow][newCol]) {
                    
                    dist[newRow][newCol] = d + 1;
                    if (newRow == n - 1 && newCol == n - 1) return d + 1;
                    q.push({d + 1, {newRow, newCol}});
                }
            }
        }

        return -1;
    }
};

class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    bool isValid(int &i, int &j, int &n, int &m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    // water cells start at height 0
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int height = it.second;

            dist[row][col] = height;

            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 0) {
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, height + 1});
                }
            }
        }

        return dist;
    }
};

class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    bool isValid(int &i, int &j, int &n, int &m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> dist(n, vector<int>(m, 0)); 
        
        queue<pair<pair<int,int>, int>> q; 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first; 
            int col = it.first.second; 
            int steps = it.second;
            dist[row][col] = steps;
            
            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i]; 
                int nCol = col + delCol[i]; 
                
                if(isValid(nRow, nCol, n, m) && vis[nRow][nCol] == 0) {
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }
        }
        
        return dist;
    }
};

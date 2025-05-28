

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int curr_col = image[sr][sc];
        if (curr_col == newColor) {
            return image;
        } else {
            image[sr][sc] = newColor;
        }
        bfs(curr_col, sr, sc, newColor, image);
        return image;
    }

    void bfs(int curr_col, int sr, int sc, int newColor,
             vector<vector<int>> &image) {
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({sr, sc});
        int row_directions[] = {-1, 1, 0, 0};  // up , down , left ,right
        int col_directions[] = {0, 0, -1, +1};

        while (!q.empty()) {
            pair<int, int> element = q.front();
            q.pop();

            int row = element.first;
            int col = element.second;

            for (int i = 0; i < 4; i++) {
                int newRow = row + row_directions[i];
                int newCol = col + col_directions[i];

                if (isValid(newRow, newCol, n, m) &&
                    image[newRow][newCol] == curr_col &&
                    image[newRow][newCol] != newColor) {
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    bool isValid(int newRow, int newCol, int n, int m) {
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) return true;
        return false;
    }
};

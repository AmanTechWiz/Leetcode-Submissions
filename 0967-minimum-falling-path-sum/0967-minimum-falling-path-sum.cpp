
class Solution{
public:
    /* Function to find the minimum
    path sum in the given matrix*/
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 

        // Create a 2D DP array to store minimum path sums
        vector<vector<int>> dp(n, vector<int>(m, 0));

        /* Initialize the first row of 
        dp with values from the matrix */
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        /* Iterate through the matrix rows
        starting from the second row*/
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                /* Calculate the minimum path sum for the
                current cell considering three possible 
                directions: up, left diagonal, and right diagonal*/

                // Up direction
                int up = matrix[i][j] + dp[i - 1][j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }

                // Right diagonal direction 
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e9;  
                }

                // Store the minimum of the three paths in dp
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        /* Find the minimum value in the last row of dp, which
        represents the minimum path sums ending at each cell*/
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        // Minimum path sum is the minimum value in last row
        return mini;
    }
};



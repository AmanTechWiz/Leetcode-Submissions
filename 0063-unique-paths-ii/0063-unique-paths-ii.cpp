
class Solution {
private:

    //Function to solve the problem using memoization
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        // Base cases
        if (i < 0 || j < 0 || matrix[i][j] == 1) return 0;
        else if(i == 0 && j == 0) return 1;
        
        // If the result is already computed, return it
        if(dp[i][j] != -1) return dp[i][j];

        /* Calculate the number of ways by
        moving up and left recursively.*/
        int up = func(i - 1, j, matrix, dp);
        int left = func(i, j - 1, matrix, dp);

        // Return the total ways
        return dp[i][j] = up + left;
    }
    
public:

    /*Function to find all unique paths to reach
    matrix[m-1][n-1] form matrix[0][0] with obstacles*/
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize DP table to memoize results
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        
        //Return the total number of paths
        return func(m-1, n-1, matrix, dp);
    }
};



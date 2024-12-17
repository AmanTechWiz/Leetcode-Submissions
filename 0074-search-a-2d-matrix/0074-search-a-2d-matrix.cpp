class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n * m - 1;
        //Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;
                
            //Calculate the row and column
            int row = mid / m, col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        // Return false if target is not found
        return false; 
    }
};
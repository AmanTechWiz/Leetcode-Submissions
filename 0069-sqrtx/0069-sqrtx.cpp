class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x;
        
        // Binary search on the answer space
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;
            
            // Check if val is less than or equal to n
            if (val <= (long long)(x)) {
                // Move to the right part
                low = mid + 1;
            } else {
                // Move to the left part
                high = mid - 1;
            }
        }
    
        return high;
    }
};
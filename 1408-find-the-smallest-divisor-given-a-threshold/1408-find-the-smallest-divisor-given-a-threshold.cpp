class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int n = nums.size();
        if (n > threshold) return -1;
        
        // Initialize binary search bounds
        int low = 1, high = *max_element(nums.begin(), nums.end());

        // Apply binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;  
    }

private:
    /* Helper function to find the
    summation of division values*/
    int sumByD(vector<int>& nums, int threshold) {
        // Size of array
        int n = nums.size(); 
        
        // Find the summation of division values
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(threshold));
        }
        return sum;
    }

};
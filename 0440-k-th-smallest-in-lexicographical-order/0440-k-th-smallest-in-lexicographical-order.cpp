class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1; // Start from 1
        k--; // Decrease k since we start counting from 1

        while (k > 0) {
            int count = countSteps(n, current, current + 1); // Count numbers in the range
            if (count <= k) {
                current++; // Move to the next prefix
                k -= count; // Decrease k by the count
            } else {
                current *= 10; // Go deeper in the tree
                k--; // We include the current number
            }
        }

        return current; // Return the kth number
    }

private:
    int countSteps(long long n, long long curr, long long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min(n + 1LL, next) - curr; // Count numbers in range [curr, next)
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};

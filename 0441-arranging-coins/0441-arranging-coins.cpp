class Solution {
public:
    int arrangeCoins(int n) {
   long long left = 1, right = n;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(mid, n)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private: 
         bool check(int mid, int n) {
        return mid <= 2L * n / (mid + 1);  }  
};
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            int totalH = 0;
            for (int p : piles) totalH += (p + mid - 1) / mid;
            if (totalH <= h) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
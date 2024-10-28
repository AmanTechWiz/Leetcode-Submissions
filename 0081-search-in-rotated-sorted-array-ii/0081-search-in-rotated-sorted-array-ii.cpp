class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return true;

              if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                (nums[low] <= target && target < nums[mid]) ? high = mid - 1 : low = mid + 1;
            } else {
                (nums[mid] < target && target <= nums[high]) ? low = mid + 1 : high = mid - 1;
            }
        }
        return false;
    }
};
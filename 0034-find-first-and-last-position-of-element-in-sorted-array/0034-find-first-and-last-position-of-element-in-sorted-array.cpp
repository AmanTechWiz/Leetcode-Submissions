class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = fo(nums,target);
        int last = lo(nums,target);
        return {first,last};
    }

    int fo(vector<int>&nums, int x){
        int low = 0, high = nums.size() - 1;
        int first = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2; 
            if(nums[mid] == x){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] > x) high = mid-1;
            else low = mid + 1;
        }
        return first;
    } 

    int lo(vector<int>&nums, int x){
        int low = 0, high = nums.size() - 1;
        int last = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2; 
            if(nums[mid] == x){
               last = mid;
                low = mid+1;
            }
            else if(nums[mid] > x) high = mid-1;
            else low = mid + 1;
        }
        return last;
    } 
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int target = accumulate(nums.begin(),nums.end(),0) - x;
        int maxLength = -1;

        while (right < nums.size()){
            sum += nums[right];

            while(sum > target && left <= right){
                sum -= nums[left];
                left++;
            }

            if(sum == target){
                maxLength = max(maxLength,right-left+1);
            }

            right++;
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;     
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0;
        for(int right=0; right<nums.size(); right++){
           if ((nums[right] & 1) == 0){
                swap(nums[left],nums[right]);
                left++;
            }
        }
        return nums;
    }
};
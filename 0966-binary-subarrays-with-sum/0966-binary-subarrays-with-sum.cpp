class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
     return compute(nums,goal) - compute(nums,goal-1);
    }

    int compute(vector<int>& nums, int goal){
        int l=0 , r=0;
        int count = 0;
        int sum = 0;

        if(goal<0) return 0;

        while(r < nums.size()){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            count += (r-l+1);
            r++;
        }
        return count;
    }
};
class Solution {
public:

int countpart(vector<int>&nums , int max){
    int n = nums.size();
    int partition = 1;
    long long subarraysum = 0;

    for(int i=0; i<n; i++){
        if(subarraysum + nums[i] <= max){
            subarraysum += nums[i];
        }else{
            partition++;
            subarraysum = nums[i];
        }
    }
    return partition;
}
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = (low+high)/2;
            int partno = countpart(nums,mid);

            if(partno > k){
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};
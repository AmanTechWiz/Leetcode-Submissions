class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            XOR ^= nums[i];
        }

        int b1=0 , b2=0;

        int rightmost = (XOR & XOR-1) ^ XOR;

        for(int i=0;i<n; i++){
            if(nums[i] & rightmost){
                b1 ^= nums[i];
            }else{
                b2 ^= nums[i];
            }
        }

        return {b1,b2};
    }
};
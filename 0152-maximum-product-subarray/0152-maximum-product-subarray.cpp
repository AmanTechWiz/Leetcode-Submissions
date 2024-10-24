class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = INT_MIN;
        int pre = 1 , suff = 1;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            
            pre *= nums[i];
            suff *= nums[n-i-1];

            product=max(product,max(pre,suff));
        }
        return product;
    }
};
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
          int n = nums.size();
       if(n>threshold) return -1; //edge case

       long long low = 1;
       long long high = *max_element(nums.begin(),nums.end());

      while(low<=high){
        long long mid = (low + high)/ 2;

        if(sumBy(nums,mid,n) <= threshold){
          high = mid - 1;
        }else{low = mid+1;}
      }
      return low;
    }
private:
    long long sumBy(vector<int>& nums, int mid , int n) {
        
        // Find the summation of division values
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(mid));
        }
        return sum;
    }  
};
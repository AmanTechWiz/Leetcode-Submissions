class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        func(0,nums.size(),answer,arr,nums);
        return answer;
    }
    
     void func(int index, int n,vector<vector<int>> &answer,vector<int> &arr,vector<int> &nums){
        if(index == n){
            answer.push_back(arr);
            return;
        }

        arr.push_back(nums[index]);
        func(index+1, n, answer, arr, nums);
        arr.pop_back();

        for(int j = index+1 ; j<n; j++){
            if(nums[j] != nums[index]){
                func(j,n,answer,arr,nums);
                return;
            }
        }
        func(n,n,answer,arr,nums);
    }
};
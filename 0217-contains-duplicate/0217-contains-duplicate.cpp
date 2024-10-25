class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){return true;}
            mp[nums[i]] = 1;
        }
        return false;
    }
};
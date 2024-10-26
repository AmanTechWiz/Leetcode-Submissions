class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>mp;

        if(n == 0) return 0;

        int longest=1;

        for(int i=0; i<n; i++){
            mp.insert(nums[i]);
        }

        for(auto it : mp){
            if(mp.find(it-1) == mp.end()){
                int cnt = 1;
                int current = it;

                while(mp.find(current+1) != mp.end()){
                    current++;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
    return longest;
    }
};
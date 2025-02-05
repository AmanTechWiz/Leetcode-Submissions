class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<int, int> mp;
        int n = fruits.size();

        while (r < n) {
            mp[fruits[r]]++;

            if (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            if (mp.size() <= 2) {
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
           int count = 0;
    for (const string& word : words) {
        // Check if the prefix is found at the beginning (position 0)
        if (word.find(pref) == 0) {
            count++;
        }
    }
    return count;
    }
};
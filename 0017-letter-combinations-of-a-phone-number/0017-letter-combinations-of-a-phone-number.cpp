class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
                if (digits.empty()) return {};
                vector<string> ans;
        string s = "";
        func(0, digits, s, ans, combos);
        return ans;
    }

public:
    void func(int ind, string digits, string s, vector<string>& ans,
              string combos[]) {
         if (ind == digits.size()) {
            ans.push_back(s);
            return;
        }

        int digit = digits[ind] - '0';
        
        // Skip invalid digits
        if (digit < 2) return;

        for (int i = 0; i < combos[digit].size(); i++) {
            s.push_back(combos[digit][i]);
            func(ind + 1, digits, s, ans, combos);
            s.pop_back();  // Backtrack
    }
              }
};
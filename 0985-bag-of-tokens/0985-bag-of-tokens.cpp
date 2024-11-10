class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
          sort(tokens.begin(), tokens.end());
        int result = 0, points = 0;
        int left = 0, right = tokens.size() - 1;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                result = max(result, ++points);
            } else if (points > 0) {
                --points;
                power += tokens[right--];
            } else {
                break;
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
  vector<int> answer;
        answer.push_back(1); 

        for (int c = 1; c <= rowIndex; c++) {
            answer.push_back(combination(rowIndex, c));
        }
        return answer;
    }

private:
    int combination(int n, int c) {
        long long ans = 1; 

        for (int j = 1; j <= c; j++) {
            ans = ans * (n - j + 1) / j; 
        }
        return ans;
    }
};
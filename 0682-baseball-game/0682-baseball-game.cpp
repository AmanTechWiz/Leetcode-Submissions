class Solution {
public:
    int calPoints(vector<string>& operations) {
          vector<int> records;
        for (const auto& op : operations) {
            if (op == "+") {
                records.emplace_back(records[records.size() - 2] + records.back());
            } else if (op == "D") {
                records.emplace_back(2 * records.back());
            } else if (op == "C") {
                records.pop_back();
            } else {
                records.emplace_back(stoi(op));
            }
        }
        return accumulate(records.begin(), records.end(), 0);
    }
};
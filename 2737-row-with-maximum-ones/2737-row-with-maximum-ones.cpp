class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = 0; 
        int index = 0;   
        int n = mat.size(); 
        int m = mat[0].size(); 

        for (int i = 0; i < n; i++) {
            sort(mat[i].begin(), mat[i].end());
            int pos = lowerbound(mat[i], m, 1); 
            int cnt = m - pos; 

            if (cnt > cnt_max) { 
                cnt_max = cnt;
                index = i;
            }
        }
        return {index, cnt_max}; 
    }

    int lowerbound(vector<int>& arr, int m, int x) {
        int low = 0, high = m - 1;
        int ans = m;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == x) {
                ans = mid;    
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
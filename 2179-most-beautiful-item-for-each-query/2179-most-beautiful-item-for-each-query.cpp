class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>answer;
        sort(items.begin(),items.end());
        int n = queries.size();

         for(int j = 1; j < items.size(); j++) {
            items[j][1] = max(items[j][1], items[j-1][1]);
        }

        for(int i=0; i<n;i++){
            int target = queries[i];
            int max = bs(items,target);
            answer.push_back(max);
        }
        return answer;
    }

    int bs(vector<vector<int>> &items, int target){
        int low = 0;
        int high = items.size()-1;

        while(low<=high){
            long long mid = (low+high)/2;
            if(items[mid][0] <= target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high>=0 ? items[high][1] : 0;
    }
};
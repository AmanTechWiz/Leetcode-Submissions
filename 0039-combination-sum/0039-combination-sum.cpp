class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> answer;
        vector<int> v;

        find(0,v,answer,target,candidates);
        return answer;
    }

      void find(int index, vector<int>&v,vector<vector<int>> &answer, int sum, vector<int>& candidates  ){
        if( sum == 0){
            answer.push_back(v);
            return;
        }

        if( sum < 0 || index >= candidates.size()){
            return;
        }

        v.push_back(candidates[index]);
        find(index,v,answer,sum-candidates[index],candidates);
        v.pop_back();
        find(index+1,v,answer,sum,candidates);
    }
};
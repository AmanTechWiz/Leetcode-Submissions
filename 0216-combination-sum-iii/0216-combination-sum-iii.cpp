class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     //your code goes here
         vector<vector<int>>answer;
         vector<int> arr;
         helper(1,n,k,answer,arr);
         return answer;
    }

    void helper(int last, int n, int k,vector<vector<int>>&answer, vector<int>&arr){
        if(n == 0 && arr.size() == k ){
            answer.push_back(arr);
            return;
        }

        if(n<=0 || arr.size() > k) return;

        for(int i = last ; i<=9 ; i++){
            if(i<=n){
                arr.push_back(i);
                helper(i+1,n-i,k,answer,arr);
                arr.pop_back();
            }else{
                break;
            }
        }
    }
};
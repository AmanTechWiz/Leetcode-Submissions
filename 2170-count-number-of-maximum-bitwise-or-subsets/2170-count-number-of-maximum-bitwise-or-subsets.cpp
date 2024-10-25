class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int MaxOr = 0;

        for(int num:nums){
            MaxOr |= num;
        }

        int Cor = 0;
        return countsubset(0,Cor,MaxOr,nums);
    }

    int countsubset(int index , int Cor, int MaxOr, vector<int>&nums){
        
        if(index == nums.size()){
            if(Cor == MaxOr)
                return 1;
            return 0;    
        }

        int takecount = countsubset(index+1, Cor|nums[index], MaxOr, nums);
        int nottakecount = countsubset(index+1, Cor, MaxOr, nums);

        return takecount + nottakecount;
    }
};
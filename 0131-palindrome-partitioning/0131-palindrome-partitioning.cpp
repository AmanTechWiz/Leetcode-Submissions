class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string>temp;
        func(0,s,answer,temp);
        return answer;
    }

    void func(int index, string s, vector<vector<string>>&answer,vector<string>&temp){
        
        if(index == s.size()){
            answer.push_back(temp);
            return;
        }

        for(int i = index; i<s.size(); i++){
            if(checkPalindrome(index,i,s)){
                temp.push_back(s.substr(index,i-index+1));
                func(i+1,s,answer,temp);
                temp.pop_back();
            }
        }
    }

    bool checkPalindrome(int index,int i,string s){
        while(index <= i){
            if(s[index++] != s[i--]){
                return false;
            }
        }
     return true;
    }
};
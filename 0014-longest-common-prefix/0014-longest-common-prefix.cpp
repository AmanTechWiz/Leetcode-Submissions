class Solution {
public:
    string longestCommonPrefix(vector<string>& V) {
        string ans = "";
        sort(V.begin(),V.end());
        int n = V.size();

        for(int i=0; i < min(V[0].size(),V[n-1].size()); i++){
            if(V[0][i] != V[n-1][i]) return ans;
            ans+=V[0][i];
        }
    return ans;
    }
};
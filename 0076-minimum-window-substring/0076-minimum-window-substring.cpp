class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int hash[256] = {0};
        int stidx = -1;
        int minlen = INT_MAX;
        int count = 0;
        int n = s.size();

        // storing all characters in t
        for(char c : t){
            hash[c]++;
        }

        while(r < n){
            if(hash[s[r]] > 0) count++;
            hash[s[r]]--;

            while(count == t.size()){
                
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    stidx = l;
                }
                
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return (stidx == -1) ? "" : s.substr(stidx , minlen);
    }
};
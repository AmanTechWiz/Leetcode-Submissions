class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];

        for(int i=0; i<256; i++){
            hash[i] = -1;
        }

        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        
        while(r<n){
            // if we already have the element in the hash table
            if(hash[s[r]] != -1){ 

                if(hash[s[r]] >= l){
                 l = hash[s[r]] + 1;
                }
            }    
                hash[s[r]] = r;
                int len = r-l+1;
                maxlen = max(len,maxlen);
                r++;
            }
            return maxlen; 
    }
};
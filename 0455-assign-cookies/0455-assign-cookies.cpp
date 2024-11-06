class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
          int n = g.size();
        int m = s.size();
        // Pointers
        int l = 0, r = 0;
        // Sorting of vectors
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Traverse through both arrays
        while (l < n && r < m) {
            /*If the current cookie can satisfy 
            the current student, move to the 
            next student*/
            if (s[r] >= g[l]) {
                l++;
            }
            // Move to next cookie
            r++;
        }
        // Return the number of students who got cookies
        return l; 
    }
};
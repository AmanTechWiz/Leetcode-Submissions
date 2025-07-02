class Solution {
public:
    int lengthOfLastWord(string s) {
          int end = s.length() - 1;

        while (end >= 0 && s[end] == ' ') {
            end--;
        }

       int cnt = 0;

       while(end >=0 && s[end] != ' '){
        cnt++;
        end--;
       }
        return cnt;
    }
};
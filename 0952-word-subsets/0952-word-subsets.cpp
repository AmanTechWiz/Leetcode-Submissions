class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxfreq(26,0);
        vector<string>answer;

        for(string &word : words2){
            vector<int>freq(26,0);

            for(char c : word){
                freq[c-'a']++;
            }

            for(int i=0; i<26; i++){
                maxfreq[i] = max(maxfreq[i],freq[i]);
            }
        }

        for(string &word : words1){
            vector<int>freq(26,0);

            for(char c : word){
                freq[c-'a']++;
            }

            bool universal = true;
            for(int i=0; i<26; i++){
                if(freq[i]<maxfreq[i]){
                    universal = false;
                    break;
                }
            }

            if(universal){
                answer.push_back(word);
            }
        } 
return answer;
    }
};
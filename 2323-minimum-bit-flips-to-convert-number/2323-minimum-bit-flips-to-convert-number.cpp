class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;
        
        /* Variable to count 
        number of set bits */
        int count = 0;

        for(int i = 0; i < 32; i++) {
            /* Update count if the 
            rightmost bit is set */
            count += (num & 1); 
            
            /* Shift the number every 
            time by 1 place */
            num = num >> 1;
        }
        return count;
    }
};
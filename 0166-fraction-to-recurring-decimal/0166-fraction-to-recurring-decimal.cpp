class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return to_string(0);

        string answer;

        if((numerator < 0) ^ (denominator <0) ){
            answer += '-';
        }

        long num = labs(numerator);
        long den = labs(denominator);

        long quotient = num / den;
        answer += to_string(quotient);

        long remainder = num % den;
        if(remainder == 0) return answer;
        
        answer += '.';

        unordered_map<long,int>mp;

        while(remainder != 0){
            if(mp.find(remainder) != mp.end()){
                answer.insert(mp[remainder],"(");
                answer+=')';
                break;
            }

            mp[remainder] = answer.size();

            remainder *= 10;
            int quo = remainder / den;
            answer+=to_string(quo);
            remainder%=den;
        }
        return answer;
    }
};
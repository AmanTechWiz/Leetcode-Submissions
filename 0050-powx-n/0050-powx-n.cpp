class Solution {
public:
    double myPow(double x, long long n) {

         if (n < 0) {
            x = 1 / x;
            // Use long to handle edge case for n = INT_MIN
            n = -n;
        }
        
        if (n==0){
            return 1.0;
        }

        if (n==1){
            return x;
        }

        if(n%2==0){
            return myPow(x*x,n/2);
        }
            return x * myPow(x,n-1);
    }
};
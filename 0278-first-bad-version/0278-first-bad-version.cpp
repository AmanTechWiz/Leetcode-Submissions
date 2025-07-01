// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int low = 1;
        long int high = n;
        long int mid;
        long int answer;

        while(low<=high){
            mid=(low+high)/2;
            if(isBadVersion(mid)){
                answer = mid;
                high=mid-1;
            }else{low=mid+1;}
        }
        return answer;
    }
};
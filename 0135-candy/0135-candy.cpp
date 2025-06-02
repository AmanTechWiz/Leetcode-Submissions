class Solution {

public:
    int candy(vector<int>& ratings) {
        //your code goes here
        int n = ratings.size();

        int i = 1;
        int sum = 1;

        while(i<n){

            //case 1 : plateau in graph

            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
           }

           // case 2 : increasing slope
           int peak = 1;

           while(i< n && ratings[i] > ratings[i-1]){
            peak += 1;
            sum += peak;
            i++;
           }

           //case 3 : downward slope
           int lowest = 1;

           while(i<n && ratings[i] < ratings[i-1]){
            sum += lowest;
            lowest++;
            i++;
           }

           if(lowest>peak){
            sum += (lowest-peak);
           }
        }
          return sum;
    }
};  
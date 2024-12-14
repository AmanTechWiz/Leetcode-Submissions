class Solution {
public:
bool possible (vector<int>bloomDay , int days , int m , int k){
    int cnt = 0 , nob = 0;
    int n = bloomDay.size();

    for(int i = 0; i < n; i++){
      if(bloomDay[i] <= days){
      cnt++;
    } else {
      nob += (cnt/k);
      cnt = 0;
      }
  }
     
  nob+= (cnt/k);
  return nob >= m; 
}

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val =  m * 1ll * k * 1ll ;
        int n = bloomDay.size();
   if(val > n) return -1;

   int minimum = INT_MAX , maximum = INT_MIN;
   for(int i=0; i<n; i++){
    minimum = min(minimum,bloomDay[i]);
    maximum = max(maximum,bloomDay[i]);
   }

  int low = minimum , high = maximum , ans = -1;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(possible(bloomDay,mid,m,k)){
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
    }
};
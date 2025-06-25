class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n= arr.size();
        int i = 0;
        while (i <n - 1 && arr[i] < arr[i + 1]){  //if it follows increasing order
            i++;  
        }
        if (i == n- 1 || i == 0){  //if i reaches n-1, we wont have dec part, and if its still 0, means we dont have an inc part 
            return false;
        }
        while (i <n- 1 && arr[i] > arr[i + 1]){  //checks for dec part
            i++;
        }
        if (i ==n- 1)  //it means we have found both inc and dec parts
            return true;
        else
            return false;
    }
};
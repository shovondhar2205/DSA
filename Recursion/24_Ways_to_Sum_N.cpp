#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int ways(int arr[], int m, int sum){
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        
        int count = 0;
        for(int i=0; i<m; i++){
            count += ways(arr, m, sum-arr[i]);
        }
        return count;
    }
    
    int countWays(int arr[], int m, int N) {
        return ways(arr, m, N);
    }
};


int main(){
    Solution s;
    int arr[] = {1,5,6};
    cout << s.countWays(arr, sizeof(arr)/sizeof(arr[0]), 7) << endl;
    return 0;
}


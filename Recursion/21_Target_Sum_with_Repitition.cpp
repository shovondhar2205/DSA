#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int subsum(vector<int> arr, int index, int n, int sum){
        // Base case
        if(sum == 0) return 1;
        if(index == n || sum < 0) return 0;

        // Recursion
        return subsum(arr, index+1, n, sum) + subsum(arr, index, n, sum-arr[index]);
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3};
    cout << s.subsum(arr, 0, arr.size(), 5) << endl;
    return 0;
}

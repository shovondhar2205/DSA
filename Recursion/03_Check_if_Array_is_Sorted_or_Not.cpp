#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool issort(vector<int>& arr, int n){
        if(n == 0 || n == 1) return true;
        
        return arr[n-1] >= arr[n-2] && issort(arr, n-1);
    }
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        return issort(arr, n);
    }
};

int main(){
    Solution s;
    vector<int> a = {10,20,30,40,50};
    cout << s.isSorted(a) << endl;
    return 0;
}


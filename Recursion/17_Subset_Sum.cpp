#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void print(vector<int> nums, int index, int n, int sum, vector<int> &ans){
        // Base case
        if(index == n) {
            ans.push_back(sum);
            return;
        }

        // Inclusion
        print(nums, index+1, n, sum+nums[index], ans);

        // Exclusion
        print(nums, index+1, n, sum, ans);
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,4,5};
    vector<int> ans;
    int sum = 0;
    s.print(arr, 0, arr.size(), sum, ans);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}

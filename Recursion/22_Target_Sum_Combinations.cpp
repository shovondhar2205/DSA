#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
  
    void solve(vector<int>& arr, int index, int target, vector<int>& temp, vector<vector<int>>& ans){
        // Base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index == arr.size() || target < 0) return;

        // Pick element
        temp.push_back(arr[index]);
        solve(arr, index, target - arr[index], temp, ans);

        // Backtrack
        temp.pop_back();

        // Skip element
        solve(arr, index + 1, target, temp, ans);
    }
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        solve(arr, 0, target, temp, ans);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.targetSumComb(nums, 5);
    for(int i=0; i<res.size(); i++){
        cout << "[";
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << ", ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}


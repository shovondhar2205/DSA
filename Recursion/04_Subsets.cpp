#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void printSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(ans);
            return;
        }

        // Inclusion
        ans.push_back(nums[i]);
        printSubsets(nums, ans, i+1,res);

        ans.pop_back();
        // Exclusion
        printSubsets(nums, ans, i+1,res);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        printSubsets(nums, ans, 0, res);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = s.subsets(arr);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}

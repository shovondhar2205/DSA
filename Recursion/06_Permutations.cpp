#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void getPermutations(vector<int>& nums, int id, vector<vector<int>>& ans){
        if(id == nums.size()){
            ans.push_back({nums});
            return;
        }

        for(int i=id; i<nums.size(); i++){
            swap(nums[id], nums[i]);
            getPermutations(nums, id+1, ans);

            // Backtracking step
            swap(nums[id], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums, 0, ans);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.permute(nums);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}

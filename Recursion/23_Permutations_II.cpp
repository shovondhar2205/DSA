#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void getPermutations(vector<int>& nums, int id, vector<vector<int>>& ans){
        // Base case
        if(id == nums.size()){
            ans.push_back({nums});
            return;
        }

        // To track the elements
        vector<bool> vis(21, 0);

        for(int i=id; i<nums.size(); i++){
            // Checking visited or not
            if(vis[nums[i]+10] == 0){
                swap(nums[id], nums[i]);
                getPermutations(nums, id+1, ans);

                // Backtrack step
                swap(nums[id], nums[i]);
                vis[nums[i]+10] = 1;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums, 0, ans);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,1,2};
    vector<vector<int>> res = s.permuteUnique(arr);
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

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& res){
        
        if(i == nums.size()){
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getSubsets(nums, ans, i+1, res);

        ans.pop_back();

        int id = i+1;
        while(id < nums.size() && nums[id] == nums[id-1]){
            id++;
        }

        getSubsets(nums, ans, id, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> res;
        getSubsets(nums, ans, 0, res);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,2};
    vector<vector<int>> result = s.subsetsWithDup(arr);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}

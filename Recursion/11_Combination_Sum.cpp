#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    set<vector<int>> s;

    void getComb(vector<int>& arr, int id, int target, vector<vector<int>>& ans, vector<int>& combin){
        if(id == arr.size() || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }


        combin.push_back(arr[id]);
        // Single choice
        getComb(arr, id+1, target-arr[id], ans, combin);

        // Multiple choice
        getComb(arr, id, target-arr[id], ans, combin);
        combin.pop_back(); // Backtrack step

        // Exclusion
        getComb(arr, id+1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getComb(arr, 0, target, ans, combin);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> ans = s.combinationSum(arr, 7);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

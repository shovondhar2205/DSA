#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& grid) {
        int n = grid.size();
        vector<int> ans;
        unordered_set<int> s;
        int a, b;
        int expsum = 0, actsum = 0;
        for(int i=0; i<n; i++){
            actsum += grid[i];

            if(s.find(grid[i]) != s.end()){
                a = grid[i];
                ans.push_back(a);
            }
            s.insert(grid[i]);
        }
        expsum = (n * (n+1)) / 2;
        b = expsum + a - actsum;
        ans.push_back(b);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,4};
    vector<int> res = s.findErrorNums(nums);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}


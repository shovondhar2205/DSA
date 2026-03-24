#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        unordered_set<int> s;
        int a, b;
        int expsum = 0, actsum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                actsum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expsum = ((n*n) * (n*n + 1))/2;
        b = expsum + a - actsum;
        ans.push_back(b);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> res = s.findMissingAndRepeatedValues(grid);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}
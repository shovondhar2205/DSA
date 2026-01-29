#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> leftsum(n, 1);
        vector<int> rightsum(n, 1);

        for(int i=1; i<n; i++){
            leftsum[i] = leftsum[i-1] + nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            rightsum[i] = rightsum[i+1] + nums[i+1];
        }

        for(int i=0; i<n; i++){
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr = {10,4,8,3};
    vector<int> res = s.leftRightDifference(arr);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}
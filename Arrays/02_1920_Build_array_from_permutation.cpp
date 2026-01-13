#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr = {0,2,1,5,3,4};
    vector<int> result = s.buildArray(arr);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\t";
    }
    cout << endl;
    return 0;
}
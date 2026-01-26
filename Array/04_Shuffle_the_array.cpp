#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // More space taking

        vector<int> ans;
        vector<int> temp1(n);
        vector<int> temp2(n);

        for(int i=0; i<n; i++){
            temp1[i] = nums[i];
            temp2[i] = nums[i+n];
        }

        int id=0;
        for(int i=0; i<n; i++){
            nums[id++] = temp1[i];
            nums[id++] = temp2[i];
        }

        // Optimized version
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }

        return ans;
    }
};
int main(){
    Solution s;
    int n = 3;
    vector<int> arr = {2,5,1,3,4,7};
    vector<int> res;
    res = s.shuffle(arr, n);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}
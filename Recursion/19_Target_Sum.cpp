#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int find(vector<int> &nums, int index, int n, int target){
        // Base Case
        if(index == n){
            return target == 0;
        }

        // Recursion
        return find(nums, index+1, n ,target-nums[index]) + find(nums, index+1, n, target+nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Calling the helping function
        return find(nums, 0, nums.size(), target);
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,1,1,1,1};
    cout << s.findTargetSumWays(arr, 3) << endl;
    return 0;
}

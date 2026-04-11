#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool find(vector<int> nums, int index, int n, int target){
        // Base Case
        if(target == 0){
            return 1;
        }
        if(index == n || target < 0){
            return 0;
        }

        // Recursion
        return find(nums, index+1, n ,target) || find(nums, index+1, n, target-nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
    }
};

int main(){
    Solution s;
    vector<int> nums{3,6,4,5};
    cout << s.find(nums, 0, nums.size(), 12) << endl;
    return 0;
}

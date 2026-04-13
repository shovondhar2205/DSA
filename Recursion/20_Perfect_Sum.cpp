#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int find(vector<int> nums, int index, int n, int target){
        // Base Case
        if(target == 0){
            return 1;
        }
        if(index == n || target < 0){
            return 0;
        }

        // Recursion
        return find(nums, index+1, n ,target) + find(nums, index+1, n, target-nums[index]);
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,5,6,1};
    cout << s.find(nums, 0, nums.size(), 8) << endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    s.runningSum(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        if (nums[low] < nums[high]) {
            return nums[low];
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            else if (nums[mid] < nums[high]) {   
                high = mid;
            }
            else {                                
                high--;
            }
        }
        return nums[low];
    }
};
int main(){
    Solution s;
    vector<int> arr = {2,2,2,0,1};
    cout << s.findMin(arr) << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1] ? 0 : 1;

        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        int st = 1, end = n-2;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }

            if(nums[mid-1] < nums[mid]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return st;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,2,1,3,5,6,4};
    cout << "Peak element is : " << s.findPeakElement(arr) << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int binsearch(vector<int>& nums, int st, int end, int target){
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                return binsearch(nums, st, mid-1, target);
            }
            else{
                return binsearch(nums, mid+1, end, target);
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binsearch(nums, 0, n-1, target);
    }
};

int main(){
    Solution s;
    vector<int> arr = {-1,0,3,5,9,12};
    cout << s.search(arr, 5) << endl;
    return 0; 
}
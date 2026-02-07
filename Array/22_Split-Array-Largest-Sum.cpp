#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isvalid(vector<int>& nums, int k, int maxvalue){
        int partition = 1, value = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxvalue) return false;

            if(nums[i] + value <= maxvalue){
                value += nums[i];
            }
            else{
                partition++;
                value = nums[i];
            }
        }
        return partition <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;

        int sum = 0, mx = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mx = max(mx, nums[i]);
        }

        int st = mx, end = sum, ans = -1;
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isvalid(nums, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {7,2,5,10,8};
    cout << s.splitArray(arr, 2) << endl;
    return 0;
}
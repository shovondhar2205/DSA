#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumsum(vector<int>& nums){
        int n = nums.size();
        int maxsum = INT16_MIN, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxsum = max(maxsum, sum);
            if(sum < 0) sum = 0;
        }
        return maxsum;
    }
    int minimumsum(vector<int>& nums){
        int n = nums.size();
        int minsum = INT16_MAX, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            minsum = min(minsum, sum);
            if(sum > 0) sum = 0;
        }
        return minsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        // If the whole array is negative then just return the maximum element of that array
        int flag = 1;
        int ans = INT16_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0){
                flag = 0;
                break;
            }
            ans = max(ans, nums[i]);
        }
        if(flag) return ans;

        int ans1 = maximumsum(nums); // Maximum subarray sum
        int arraysum = 0;
        for(int i=0; i<nums.size(); i++){
            arraysum += nums[i]; // calculating the total sum of the array
        }
        int ans2 = arraysum - minimumsum(nums); // subtracting the minimum subarray sum to get the maximum subarray sum

        return max(ans1, ans2); // chose the maximum one
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,-2,3,-2};
    cout << "Maximum sum is : " << s.maxSubarraySumCircular(arr) << endl;
    return 0;
}
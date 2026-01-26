#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int st = 0, end, sum=0, maxsum=INT16_MIN;

        // Brute force approach
        for(st=0; st<nums.size(); st++){
            int sum = 0;
            for(end=st; end<nums.size(); end++){
                sum += nums[end];
                maxsum = max(maxsum, sum);
            }
        }

        // Kadane's Algorithm
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxsum = max(sum, maxsum);
            if(sum < 0) sum = 0;
        }

        return maxsum;
    }
};
int main(){
    Solution s;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray sum is " << s.maxSubArray(arr) << endl;
    return 0;
    
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Brute force approach TC : O(n^2)
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i != j){
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;

        // Using Prefix & Suffix array TC : O(n) 
        int n = nums.size();
        vector<int> ans(n, 1);

        vector<int> prefix1(n, 1);
        vector<int> suffix1(n, 1);

        suffix1[0] = n-1;
        for(int i=n-2; i>=0; i--){
            suffix1[i] = suffix1[i+1] * nums[i+1];
        }

        prefix1[0] = 1;
        for(int i=1; i<n; i++){
            prefix1[i] = prefix1[i-1] * nums[i-1];
        }

        for(int i=0; i<n; i++){
            ans[i] = suffix1[i] * prefix1[i];
        }

        return ans;

        // Optimal approach(Prefix and Suffix variable) TC : O(n) & SC : O(1)
        int n = nums.size();
        vector<int> ans(n, 1);

        int suffix = 1;

        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--){
            suffix = suffix * nums[i+1];
            ans[i] = suffix * ans[i];
        }

        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.productExceptSelf(nums);
    for(int i=0; i<res.size(); i++){ 
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] < 0){
                swap(maxprod, minprod);
            }

            maxprod = max(nums[i], maxprod*nums[i]);
            minprod = min(nums[i], minprod*nums[i]);

            ans = max(maxprod, ans);

        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr = {2,3,-2,4};
    cout << "Maximum product is : " << s.maxProduct(arr) << endl;
    return 0;
}
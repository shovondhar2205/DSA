#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Solved using 2 pointers approach TC : O(nlogn * n^3)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n;){
                
                int k = j+1, l = n-1;
                while(k < l){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j-1]) j++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,0,-1,0,-2,2};
    vector<vector<int>> res = s.fourSum(arr, 0);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


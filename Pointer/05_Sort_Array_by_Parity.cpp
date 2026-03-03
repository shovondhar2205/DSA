#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int lp = 0, rp = n-1;

        while(lp < rp){
            if(nums[lp] % 2 == 0){
                lp++;
            }
            else{
                swap(nums[lp], nums[rp]);
                rp--;
            }
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,1,2,4};
    s.sortArrayByParity(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << "\t";
    }
    return 0;
}
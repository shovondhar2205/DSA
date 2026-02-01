#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Brute force approach
        int n = nums.size();
        if(n == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        for(int i=1; i<nums.size()-1; i++){
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return -1;


        // Binary Search
        int n = nums.size();
        if(n == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int st = 1, end = n-2;
        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            if(mid % 2 == 0){
                if(nums[mid-1] == nums[mid]){
                    end = mid - 1;
                }
                else{
                    st = mid + 1;
                }
            }
            else{
                if(nums[mid-1] == nums[mid]){
                    st = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            
        }

        return -1;
    }
};
int main(){
    Solution s;
    vector<int> arr = {3,3,7,7,10,11,11};
    cout << s.singleNonDuplicate(arr) << endl;
    return 0;
}
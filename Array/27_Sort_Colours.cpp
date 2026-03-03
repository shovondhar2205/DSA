#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Brute Force Approach
        sort(nums.begin(), nums.end());
        return;
    

        // Optimal Approach
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        int id = 0;
        for(int i=0; i<count0; i++){
            nums[id++] = 0;
        }
        for(int i=0; i<count1; i++){
            nums[id++] = 1;
        }
        for(int i=0; i<count2; i++){
            nums[id++] = 2;
        }
        return;
    
        
        // Optimized Solution
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        
        return;
    }
};

int main(){
    Solution sh;
    vector<int> arr = {2,0,2,1,1,0};
    sh.sortColors(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << "\t";
    }
    return 0;
}
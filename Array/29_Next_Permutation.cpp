#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // step:1 :- Find the pivot
        int n = nums.size();
        int pivot = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        // if pivot not found
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // step:2 :- swap the pivot and just larger element than the pivot 
        for(int i=n-1; i>pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // step:3 :- reverse (pivot-1 to n-1)
        int i= pivot+1, j = n-1;
        while(i <= j){
            swap(nums[i++], nums[j--]);
        }

        return;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3};
    s.nextPermutation(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << "\t";
    }
    return 0;
}
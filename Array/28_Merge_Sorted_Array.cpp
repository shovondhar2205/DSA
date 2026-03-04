#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, id = m+n-1;
        while(i>=0 && j >=0){
            if(nums1[i] >= nums2[j]){
                nums1[id--] = nums1[i--];
            }
            else{
                nums1[id--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[id--] = nums2[j--];
        }
        return;
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {1,2,3,0,0,0};
    vector<int> arr2 = {2,5,6};
    int m = 3, n = 3;
    s.merge(arr1, m, arr2, n);
    for(int i=0; i<arr1.size(); i++){
        cout << arr1[i] << "\t";
    }
    return 0;
}
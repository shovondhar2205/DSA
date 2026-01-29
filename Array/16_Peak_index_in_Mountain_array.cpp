#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Brute force approach
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                return i;
            }
        }
        return -1;


        // Binary Search
        int n = arr.size();
        int st = 1, end = n-2;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }

            if(arr[mid] > arr[mid-1]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> arr = {0,2,1,0};
    cout << s.peakIndexInMountainArray(arr) << endl;
    return 0;
}
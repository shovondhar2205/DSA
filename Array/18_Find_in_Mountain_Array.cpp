#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int get(vector<int> &arr, int index){
        return arr[index];
    }
    int length(vector<int> &arr){
        return arr.size();
    }

    int findInMountainArray(int target, vector<int> &mountainArr) {
        int n = length(mountainArr);
        int st = 1, end = n-2, peak = 0;

        // Finding the peak value
        while(st <= end){
            int mid = st + (end - st)/2;
            if(get(mountainArr, mid-1) < get(mountainArr, mid) && get(mountainArr, mid) > (mountainArr, mid+1)){
                peak = mid;
                break;
            }

            if(get(mountainArr, mid-1) < get(mountainArr, mid)){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        // Finding the target in the ascending side
        st = 0, end = peak;
        while(st <= end){
            int mid = st + (end-st)/2;
            int val = get(mountainArr, mid);

            if(val == target){
                return mid;
            }

            if(target > val){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            
        }

        // Finding the target in the descending side
        st = peak+1, end = n-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            int val = get(mountainArr, mid);

            if(val == target){
                return mid;
            }

            if(target < val){
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
    vector<int> arr = {1,2,3,4,5,3,1};
    cout << s.findInMountainArray(3, arr) << endl;
    return 0;
}
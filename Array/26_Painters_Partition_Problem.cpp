#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int n, int k, int maxtime){
        int painter = 1, mtime = 0;
        for(int i=0; i<n; i++){
            if(mtime + arr[i] <= maxtime){
                mtime += arr[i];
            }
            else{
                painter++;
                mtime = arr[i];
            }
        }
        return painter <= k ? true : false; 
    }
    
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0, maxval = INT16_MIN;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            maxval = max(maxval, arr[i]);
        }
        
        int st = maxval, end = sum, ans = -1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {5,10,30,20,15};
    int k = 3;
    cout << s.minTime(arr, k) << endl;
    return 0;
}
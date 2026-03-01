#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int> &stalls, int n, int k, int mindist){
        int cows = 1, lastpos = stalls[0];
        
        for(int i=0; i<n; i++){
            if(stalls[i]-lastpos >= mindist){
                cows++;
                lastpos = stalls[i];
            }
            if(cows == k) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int maxval = stalls[n-1], minval = stalls[0];
        
        int st = 1, end = maxval-minval, ans = -1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            
            if(isPossible(stalls, n, k, mid)){
                ans = mid;
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,2,4,8,9};
    int cows = 3;
    cout << s.aggressiveCows(arr, cows) << endl;
    return 0;
}
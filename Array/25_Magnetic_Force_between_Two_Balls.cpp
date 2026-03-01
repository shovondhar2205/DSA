#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& position, int n, int m, int mindist){
        int balls = 1, lastpos = position[0];

        for(int i=0; i<n; i++){
            if(position[i]-lastpos >= mindist){
                balls++;
                lastpos = position[i];
            }
            if(balls == m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int st = 1, end = position[n-1]-position[0], ans = -1;
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isPossible(position, n, m, mid)){
                ans = mid;
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,4,7};
    int balls = 3;
    cout << s.maxDistance(arr, balls) << endl;
    return 0; 
}
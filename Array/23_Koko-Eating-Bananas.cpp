#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Brute Force approach
        int maxlen = 0;

        for(int i=0; i<piles.size(); i++){
            maxlen = max(maxlen, piles[i]);
        }

        for(int k=1; k<=maxlen; k++){
            long long hour = 0;

            for(long long i=0; i<piles.size(); i++){
                hour += (piles[i] + k-1) / k;
            }

            if(hour <= h) return k;
        }
        
        return -1;


        // Binary Search approach
        int st = 0, end = 0, ans = 0;
        long long sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += piles[i];
            end = max(end, piles[i]);
        }
        st = sum/h;
        if(st == 0) st = 1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            int total_time = 0;
            for(int i=0; i<piles.size(); i++){
                total_time += piles[i]/mid;
                if(piles[i] % mid){
                    total_time++;
                }
            }

            if(total_time > h){
                st = mid + 1;
            }
            else{
                ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,6,7,11};
    cout << s.minEatingSpeed(arr, 8) << endl;
    return 0;
}
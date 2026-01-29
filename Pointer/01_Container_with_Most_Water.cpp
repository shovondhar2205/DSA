#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {

        // Brute force Approach TC : O(n^2)
        int mw = 0, width = 0, ht = 0, area = 0;
        for(int i=0; i<height.size(); i++){
            for(int j=i+1; j<height.size(); j++){
                width = j-i; // calculate the width
                ht = min(height[i], height[j]); //calculate the max height
                area = width * ht;
                mw = max(mw, area);
            }
        }
        return mw;

        // Using 2 pointer approach TC : O(n)
        int n = height.size();
        int lp = 0, rp = n-1, maxwater = 0;
        while(lp < rp){
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            int area = width * ht;
            maxwater = max(maxwater, area);
            height[lp] < height[rp] ? lp++ : rp--; // shifting the pointers according to minimum
        }
        return maxwater;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(arr) << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int GCD(int a, int b){
        if(b == 0) return a;
        return GCD(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return GCD(nums[0], nums[nums.size()-1]);
    }
};

int main(){
    Solution s;
    vector<int> arr = {7,5,6,8,3};
    cout << s.findGCD(arr) << endl;
    return 0;
}

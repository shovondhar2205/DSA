#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Using Brute Force approach
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int prev1 = 2;
        int prev2 = 1;
        int curr;
        for(int i=3; i<=n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr; 
        }

        return prev1;
    }

    // Using Recursion
    int climbStairs(int n) {
        if(n <= 1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}

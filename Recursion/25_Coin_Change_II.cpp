#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Using Recursion
    int ways(vector<int>& coins, int amount, int index, int n){
        if(amount == 0) return 1;
        if(index == n || amount < 0) return 0;

        return ways(coins, amount, index+1, n) + ways(coins, amount-coins[index], index, n);
    }

    int change(int amount, vector<int>& coins) {
        return ways(coins, amount, 0, coins.size());
    }


    // Using memoization
    int ways(vector<int>& coins, int amount, int index, int n, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(index == n || amount < 0) return 0;

        if(dp[index][amount] != -1) return dp[index][amount];
        
        int count = 0;
        // skip current coin
        count += ways(coins, amount, index+1, n, dp);
        // take current coin
        count += ways(coins, amount-coins[index], index, n, dp);

        return dp[index][amount] = count;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return ways(coins, amount, 0, coins.size(), dp);
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,5};
    cout << s.change(5, arr) << endl;
    return 0;
}

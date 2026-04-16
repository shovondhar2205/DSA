#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Using Recursion
    int ways(vector<int>& coins, int amount, int index, int n){
        if(amount == 0) return 0;  // no more coins needed
        if(index == n || amount < 0) return 1e9;  // large value (invalid)

        // skip current coin
        int skip = ways(coins, amount, index+1, n);

        // take current coin (add 1 count)
        int take = 1 + ways(coins, amount - coins[index], index, n);

        return min(take, skip);
    }

    int numSquares(int n) {
        vector<int> coins;
        for(int i=1; i*i<=n; i++){
            coins.push_back(i*i);
        }

        return ways(coins, n, 0, coins.size());
    }

    // Using Memoization
    int ways(vector<int>& coins, int amount, int index, int n, vector<vector<int>>& dp){
        if(amount == 0) return 0;  // no more coins needed
        if(index == n || amount < 0) return 1e9;  // large value (invalid)

        if(dp[index][amount] != -1) return dp[index][amount];

        // skip current coin
        int skip = ways(coins, amount, index+1, n, dp);

        // take current coin (add 1 count)
        int take = 1 + ways(coins, amount - coins[index], index, n, dp);

        return dp[index][amount] = min(take, skip);
    }

    int numSquares(int n) {
        vector<int> coins;
        for(int i=1; i*i<=n; i++){
            coins.push_back(i*i);
        }
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(n+1, -1));

        return ways(coins, n, 0, coins.size(), dp);
    }
};

int main(){
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}

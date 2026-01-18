#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT16_MAX;
        int sell1 = 0;

        int buy2 = INT16_MAX;
        int sell2 = 0;

        for(int i=0; i<prices.size(); i++){
            buy1 = min(buy1, prices[i]);
            sell1 = max(sell1, prices[i]-buy1);

            buy2 = min(buy2, prices[i]-sell1);
            sell2 = max(sell2, prices[i]-buy2);
        }
        return sell2;
    }
};
int main(){
    Solution* s = new Solution();

    vector<int> arr = {3,3,5,0,0,3,1,4};
    cout << s->maxProfit(arr) << endl;
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> ans(1,1);
        while(n > 1){
            int carry = 0, res, size = ans.size();
            for(int i=0; i<size; i++){
                res = (ans[i] * n) + carry;
                carry = res / 10;
                ans[i] = res %  10;
            }
            
            while(carry){
                ans.push_back(carry % 10);
                carry /= 10;
            }
            
            n--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    int n = 10;
    vector<int> res = s.factorial(n);
    for(int i=0; i<res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    return 0;
}


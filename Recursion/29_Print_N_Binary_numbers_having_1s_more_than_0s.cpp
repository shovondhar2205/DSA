#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    void help(int n, vector<string>& ans, string& temp, int zero, int one){
        // Base case
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        // Filling the zeros only when ones are more than zeros
        if(zero < one){
            temp.push_back('0');
            help(n, ans, temp, zero+1, one);
            temp.pop_back();
        }
        
        // Filling the ones
        temp.push_back('1');
        help(n, ans, temp, zero, one+1);
        temp.pop_back();
    }
    
    vector<string> NBitBinary(int n) {
        vector<string> ans;
        string temp;
        // Calling the helping function
        help(n, ans, temp, 0, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> res = s.NBitBinary(2);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    } 
    return 0;
}

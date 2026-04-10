#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void parentheses(int n, int left, int right, vector<string> &ans, string &temp){
        // Base condition
        if(left + right == 2*n){
            ans.push_back(temp);
            return;
        }

        // Adding left parentheses
        if(left < n){
            temp.push_back('(');
            parentheses(n, left+1, right, ans, temp);
            // Bactrack step
            temp.pop_back();
        }

        // Adding right parentheses
        if(right < left){
            temp.push_back(')');
            parentheses(n, left, right+1, ans, temp);
            // Backtrack step
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        parentheses(n, 0, 0, ans, temp);
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}

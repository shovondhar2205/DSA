#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool ispalindrome(string s, int lp, int rp){
        while(lp <= rp){
            if(s[lp] != s[rp]) return false;
            lp++;
            rp--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int lp = 0, rp = s.size()-1;
        while(lp <= rp){
            if(s[lp] != s[rp]){
                return ispalindrome(s, lp+1, rp) || ispalindrome(s, lp, rp-1);
            }
            lp++;
            rp--;
        }
        return true;
    }
};
int main(){
    Solution s;
    string sh = "abca";
    cout << s.validPalindrome(sh) << endl;
    return 0;
}
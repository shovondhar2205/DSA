#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
  public:
    // Brute Force approach TC : O(n^2)
    bool palindrome(string s, int size){
        for (int i = 0; i < size; i++) {
            if (s[i] != s[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
    int minChar(string &s) {
        int n = s.size();
        string ans = "";
        int st = 0, end = s.size()-1;
        while(st <= end){
            if(palindrome(s, n)){
                st++;
                end--;
            }
            else{
                ans += s[end];
                end--;
                n--;
            }
        }
        return ans.size();
    }


    // Using KMP Algorithm TC : O(n)
    int minChar(string &s) {
        // original size
        int size = s.size();
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        s += '$';
        s += rev;
        
        int n = s.size(); // new size with $ and reverse
        vector<int> lps(n, 0);
        int pre = 0, suf = 1;
        while(suf < s.size()){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre == 0){
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        
        return size - lps[n-1];
        
    }
};


int main(){
    Solution s;
    string a = "abc";
    cout << s.minChar(a) << endl;
    return 0;
}


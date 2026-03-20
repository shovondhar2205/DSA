#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    // Brute Force Approach TC : O(nm)
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for(int i = 0; i <= n - m; i++) {
            int first = i;
            int second = 0;
            while(second < m){
                if(haystack[first] != needle[second]){
                    break;
                }
                else{
                    first++;
                    second++;
                }
            }

            if(second == m) {
                return first - second;
            }
        }
        return -1;
    }

    // Using KMP Algorithm TC : O(n+m)
    // Finding the LPS values
    void LPS(vector<int> &lps, string s) {
        int pre = 0, suf = 1;
        while(suf < s.size()){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre == 0){
                    lps[suf] = 0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        
    }

    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        LPS(lps, needle);

        int first = 0;
        int second = 0;
        while(second < m && first < n){
            if(haystack[first] == needle[second]){
                first++;
                second++;
            }
            else{
                if(second == 0){
                    first++;
                }
                else{
                    second = lps[second-1];
                }
            }
        }

        if(second == m){
            return first - second;
        }
        return -1;

    }
};

int main(){
    Solution s;
    string a = "sadbutsad";
    string b = "sad";
    cout << s.strStr(a, b) << endl;
    return 0;
}

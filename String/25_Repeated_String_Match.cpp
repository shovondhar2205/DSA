#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
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

    int KMPmatch(string haystack, string needle) {
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
            return 1;
        }
        return 0;

    }

    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;

        int repeat = 1;
        string temp = a;

        while(temp.size() < b.size()){
            temp += a;
            repeat++;
        }

        // KMP Pattern search
        if(KMPmatch(temp, b) == 1){
            return repeat;
        }

        // Temp+a again KMP search
        if(KMPmatch(temp+a, b) == 1){
            return repeat+1;
        }

        return -1;

    }
};

int main(){
    Solution s;
    string a = "abcd";
    string b = "cdabcdab";
    cout << s.repeatedStringMatch(a, b) << endl;
    return 0;
}
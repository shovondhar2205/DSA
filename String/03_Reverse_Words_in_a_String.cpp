#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Solved in O(n) TC
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++){
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(word.length() > 0){
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

int main(){
    Solution s;
    string sh = "the sky is blue";
    cout << s.reverseWords(sh) << endl;
    return 0;
}
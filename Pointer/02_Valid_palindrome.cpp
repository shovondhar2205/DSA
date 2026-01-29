#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {

        // Brute force approach
        string ch = "";
        for(int i=0; i<s.size(); i++){
            if(!isalnum(s[i])) continue;
            ch.push_back(tolower(s[i]));
        }
        int lp = 0, rp = ch.size()-1;
        while(lp < rp){
            if(ch[lp] != ch[rp]) return false;
            lp++;
            rp--;
        }
        return true;

        // Optimal code
        int n = s.size();
        int lp = 0, rp = n-1;
        while(lp < rp){
            while(lp < rp && !isalnum(s[lp])) lp++;
            while(lp < rp && !isalnum(s[rp])) rp--;

            if(tolower(s[lp]) != tolower(s[rp])) return false;

            lp++;
            rp--;
        }
        return true;
    }
};
int main(){
    Solution s;
    string sh = "A man, a plan, a canal: Panama";
    cout << s.isPalindrome(sh) << endl;
    return 0;
}
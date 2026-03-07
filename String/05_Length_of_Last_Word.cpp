#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        while(i >= 0 && s[i] != ' '){
            len++;
            i--;
        }
        return len;
    }
};

int main(){
    Solution s;
    string a = "Hello World";
    cout << s.lengthOfLastWord(a) << endl;
    return 0;
}
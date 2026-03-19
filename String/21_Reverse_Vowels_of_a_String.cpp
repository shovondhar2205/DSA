#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vowel;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vowel += s[i];
                s[i] = '#';
            }
        }

        reverse(vowel.begin(), vowel.end());
        int first = 0;
        int second = 0;
        // int second = vowel.size()-1;
        while(second < vowel.size()){
            if(s[first] == '#'){
                s[first] = vowel[second];
                second++;
            }
            first++;
        }

        return s;
    }
};

int main(){
    Solution s;
    string a = "IceCreAm";
    cout << s.reverseVowels(a) << endl;
    return 0;
}
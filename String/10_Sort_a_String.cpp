#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    string sort(string s) {
        vector<int> alpha(26, 0);
        
        for(int i=0; i<s.size(); i++){
            alpha[s[i]-'a']++;
        }
        string ans;
        for(int i=0; i<26; i++){
            char c = 'a'+i;
            while(alpha[i]){
                ans += c;
                alpha[i]--;
            }
        }
        return ans;
    
    }
};

int main(){
    Solution s;
    string a = "edcab";
    cout << s.sort(a) << endl;
    return 0;
}


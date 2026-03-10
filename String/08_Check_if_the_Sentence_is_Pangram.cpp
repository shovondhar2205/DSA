#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alpha(26, 0);

        for(int i=0; i<sentence.size(); i++){
            int id = sentence[i]-'a';
            alpha[id] = 1;
        }

        for(int i=0; i<26; i++){
            if(alpha[i] == 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    string sh = {"thequickbrownfoxjumpsoverthelazydog"};
    cout << s.checkIfPangram(sh) << endl;
    return 0;
}
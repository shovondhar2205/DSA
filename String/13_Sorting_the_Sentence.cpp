#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0;
        int id = 0;

        // Extract out every word and arrange them 
        while(id < s.size()){
            if(s[id] == ' '){
                int pos = temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            }
            else{
                temp += s[id];
            }
            id++;
        }

        // Extract out the last word and arrange them
        int pos = temp[temp.size()-1]-'0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        count++;

        // put the word into the string
        for(int i=1; i<=count; i++){
            temp += ans[i];
            temp += ' ';
        }

        // Extract out the last space
        temp.pop_back();
        return temp;
    }
};

int main(){
    Solution s;
    string a = "is2 sentence4 This1 a3";
    cout << s.sortSentence(a) << endl;
    return 0;
}


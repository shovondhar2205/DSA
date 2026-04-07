#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getAllParts(string s, vector<string>& part, vector<vector<string>>& ans){
        if(s.size() == 0){
            ans.push_back(part);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string p = s.substr(0, i+1);

            if(isPalindrome(p)){
                part.push_back(p);
                getAllParts(s.substr(i+1), part, ans);

                // Backtrack step
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;

        getAllParts(s, part, ans);
        return ans;
    }
};

int main(){
    Solution s;
    string a = "aab";
    vector<vector<string>> res = s.partition(a);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);
        vector<pair<int, char>> alpha;

        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        
        for(int i=0; i<128; i++){
            if(freq[i] > 0){
                alpha.push_back({freq[i], char(i)});
            }
        }
        sort(alpha.begin(), alpha.end(), greater<pair<int, char>>());

        string ans;
        for(int i=0; i<alpha.size(); i++){
            while(alpha[i].first--){
                ans += alpha[i].second;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    string a = "tree";
    cout << s.frequencySort(a) << endl;
    return 0;
}
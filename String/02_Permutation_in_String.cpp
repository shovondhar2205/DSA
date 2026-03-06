#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isFreqSame(int freq1[26], int freq2[26]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i=0; i<s1.length(); i++){
            freq[s1[i] - 'a']++;
        }

        int windsize = s1.length();

        for(int i=0; i<s2.length(); i++){
            int windid = 0, id = i;
            int windfreq[26] = {0};

            while(windid < windsize && id < s2.length()){
                windfreq[s2[id] - 'a']++;
                windid++;
                id++;
            }

            if(isFreqSame(freq, windfreq)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    string a = "ab";
    string b = "eidbaooo";
    cout << s.checkInclusion(a, b) << endl;
    return 0;

}
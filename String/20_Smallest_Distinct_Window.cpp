#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
    int findSubString(string& str) {
        vector<int> count(256, 0);
        int first = 0, second = 0, len = str.size(), diff = 0;
        
        // Counting the distinct elements
        while(first < str.size()){
            if(count[str[first]] == 0){
                diff++;
            }
            count[str[first]]++;
            first++;
        }
        
        for(int i=0; i<256; i++){
            count[i] = 0;
        }
        
        first = 0;
        while(second < str.size()){
            while(diff > 0 && second < str.size()){
                if(count[str[second]] == 0){
                    diff--;
                }
                
                count[str[second]]++;
                second++;
            }
            len = min(len, second-first);
            
            while(diff != 1){
                len = min(len, second-first);
                count[str[first]]--;
                
                if(count[str[first]] == 0){
                    diff++;
                }
                first++;
            }
        }
        return len;
    }
};

int main(){
    Solution s;
    string a = "aabcbcdbca";
    cout << s.findSubString(a) << endl;
    return 0;
}
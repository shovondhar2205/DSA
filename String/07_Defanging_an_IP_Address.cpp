#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int idx = 0;
        string ans;
        while(idx < address.size()){
            if(address[idx] == '.'){
                ans = ans + "[.]";
            }
            else{
                ans = ans + address[idx];
            }
            idx++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string IP = "1.1.1.1";
    cout << s.defangIPaddr(IP) << endl;
    return 0;
}
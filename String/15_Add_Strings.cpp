#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string add(string num1, string num2){
        string ans;
        int id1 = num1.size()-1;
        int id2 = num2.size()-1;
        int sum, carry = 0;

        // while id2 >= 0
        while(id2 >= 0){
            sum = (num1[id1]-'0') + (num2[id2]-'0') + carry;
            carry = sum/10;
            char c = '0'+sum%10;
            ans += c;
            id2--;
            id1--;
        }

        // while id1 >= 0
        while(id1 >= 0){
            sum = (num1[id1]-'0') + carry;
            carry = sum/10;
            char c = '0'+sum%10;
            ans += c;
            id1--;
        }

        // if carry exixts add it to the final string
        if(carry){
            ans += '1';
        }
        // reverse the string
        reverse(ans.begin(), ans.end());

        return ans;
    }

    string addStrings(string num1, string num2) {
        // Handling the sizesx of the strings
        if(num1.size() < num2.size()){
            return add(num2, num1);
        }
        else{
            return add(num1, num2);
        }
    }
};

int main(){
    Solution s;
    string a = "11";
    string b = "123";
    cout << s.addStrings(a, b) << endl;
    return 0;
}

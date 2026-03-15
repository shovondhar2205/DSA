#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int num(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    }

    int romanToInt(string s) {
        int id = 0;
        int sum = 0;
        while(id < s.size()-1){
            if(num(s[id]) < num(s[id+1])){
                sum -= num(s[id]);
            }
            else{
                sum += num(s[id]);
            }
            id++;
        }
        sum += num(s[s.size()-1]);
        return sum;
    }
};

int main(){
    Solution s;
    string ro = "CD";
    cout << s.romanToInt(ro) << endl;
    return 0;
}

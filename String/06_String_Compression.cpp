#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int id = 0;
        int n = chars.size();

        for(int i=0; i<n; i++){
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch){
                count++;
                i++;
            }

            if(count == 1){
                chars[id++] = ch;
            }
            else{
                chars[id++] = ch;
                string str = to_string(count);
                for(char dig : str){
                    chars[id++] = dig;
                }
            }

            i--;
        }
        chars.resize(id);
        return id;
    }
};

int main(){
    Solution s;
    vector<char> arr = {'a','a','b','b','c','c','c'};
    cout << s.compress(arr) << endl;
    return 0;
}
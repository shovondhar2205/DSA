#include<iostream>
using namespace std;

class Solution {
public:
    int help(int n, int index){
        if(n == 0) return 1;
        if(n < 0 || index == 0) return 0;

        int skip = help(n, index-1);

        int take = 0;
        if(n-index >= 0){
            take = index * help(n-index, index);
        }
        
        return max(skip, take);
    }
    
    int integerBreak(int n) {
        return help(n, n-1);
    }
};

int main(){
    Solution s;
    cout << s.integerBreak(10) << endl;
    return 0;
}

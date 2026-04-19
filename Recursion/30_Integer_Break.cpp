#include<iostream>
using namespace std;

class Solution {
public:
    int help(int n, int index){
        // Base case
        if(n == 0) return 1;
        if(n < 0 || index == 0) return 0;

        // Skipping the element
        int skip = help(n, index-1);

        // Taking the element
        int take = 0;
        if(n-index >= 0){
            take = index * help(n-index, index);
        }
        
        // Returning the maximum possible value
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

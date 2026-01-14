#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "++X" || operations[i] == "X++"){
                count++;
            }
            else{
                count--;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<string> arr = {"--X", "X++", "X++"};
    cout << s.finalValueAfterOperations(arr) << endl;
    return 0;
}
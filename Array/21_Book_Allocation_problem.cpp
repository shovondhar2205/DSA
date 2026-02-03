#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void AllocateBooks(){
        for(int i=0; i<10; i++){
            cout << i << endl;
        }
    }
};
int main(){
    Solution* s = new Solution();

    s->AllocateBooks();
    return 0;
}
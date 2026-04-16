#include<iostream>
using namespace std;

class Solution {
  public:
    // To print the total path of the tower
    void TOH(int n, int source, int help, int dest) {
        if(n == 1){
            cout << "Move disk " << n << " from " << source << " to " << dest << endl;
            return;
        }

        TOH(n-1, source, dest, help);
        cout << "Move disk " << n << " from " << source << " to " << dest << endl;

        TOH(n-1, help, source, dest);
    }

    // To print the count of steps to complete the tower
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n == 1){
            return 1;
        }
        
        int count = 0;
        count += towerOfHanoi(n-1, from, to, aux);
        count += 1;
        count += towerOfHanoi(n-1, aux, from, to);

        return count;
    }
};

int main(){
    Solution s;
    s.TOH(3, 1, 2, 3);
    cout << endl;
    cout << s.towerOfHanoi(3, 1, 2, 3) << endl;
    return 0;
}

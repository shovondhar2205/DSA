#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    // TC : O(n^2)
    int winner(vector<bool>& person, int n, int index, int person_left, int k){
        if(person_left == 1){
            for(int i=0; i<n; i++){
                if(person[i] == 0){
                    return i;
                }
            }
        }

        // Find the position of kill
        int kill = (k-1) % person_left;

        while(kill--){
            index = (index+1) % n;
            while(person[index] == 1){
                index = (index+1) % n ;
            }
        }

        person[index] = 1;

        // Next alive person
        while(person[index] == 1){
            index = (index+1) % n ;
        }

        return winner(person, n, index, person_left-1, k);
    }

    int findTheWinner(int n, int k){
        vector<bool> person(n, 0);
        return winner(person, n, 0, n, k) + 1;
    }

    // Using Josephus Algorithm TC : O(n)
    int winner(int n, int k){
        if(n == 1) return 0;
        return (winner(n-1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return winner(n, k) + 1;
    }
};

int main(){
    Solution s;
    cout << s.findTheWinner(5, 2) << endl;
    return 0;
}

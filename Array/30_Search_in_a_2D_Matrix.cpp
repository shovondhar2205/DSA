#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Brute Force TC : O(n^2)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix[0].size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }

    // Using Binary Search TC : O(n*m)
    bool searchinrow(vector<vector<int>>& matrix, int target, int row){
        int n = matrix[0].size();
        int st = 0, end = n-1;

        // Searching the correct value
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(target > matrix[row][mid]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        } 
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, er = m-1;

        // Searching the correct row
        while(sr <= er){
            int midr = sr + (er - sr) / 2;
            if(target >= matrix[midr][0] && target <= matrix[midr][n-1]){
                return searchinrow(matrix, target, midr);
            }
            else if(target >= matrix[midr][n-1]){
                sr = midr + 1;
            }
            else{
                er = midr - 1;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << s.searchMatrix(arr, 8) << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
  public:
    void helper(vector<vector<int>>& maze, int row, int col, string path, vector<string>& ans){
        int n = maze.size();
        if(row < 0 || col < 0 || row >= n || col >=n || maze[row][col] == 0 || maze[row][col] == -1){
            return;
        }
        
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        maze[row][col] = -1;
        
        // Down
        helper(maze, row+1, col, path+"D", ans);
        
        // Left
        helper(maze, row, col-1, path+"L", ans);
        
        // Right
        helper(maze, row, col+1, path+"R", ans);
        
        // Up
        helper(maze, row-1, col, path+"U", ans);
        
        // Backtracking step
        maze[row][col] = 1;
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        string path = "";
        
        helper(maze, 0, 0, path, ans);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> ans = s.ratInMaze(mat);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\t";
    }
    cout << endl;
    return 0;
}

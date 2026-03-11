#include<iostream>
#include<string>
using namespace std;

class Solution {
  public:
    void rotateclockwise(string &s){
        char c = s[s.size()-1];
        int id = s.size()-2;
        while(id >= 0){
            s[id+1] = s[id];
            id--;
        }
        s[0] = c;
        return;
    }
    
    void rotateanticlockwise(string &s){
        char c = s[0];
        int id = 1;
        while(id < s.size()){
            s[id-1] = s[id];
            id++;
        }
        s[s.size()-1] = c;
        return;
    }
    
    bool isRotated(string& s1, string& s2) {
        if(s1.size() != s2.size()) return false;
        
        string clockwise, anticlockwise;
        
        clockwise = s1;
        rotateclockwise(clockwise);
        rotateclockwise(clockwise);
        
        if(clockwise == s2) return true;
        
        anticlockwise = s1;
        rotateanticlockwise(anticlockwise);
        rotateanticlockwise(anticlockwise);
        
        if(anticlockwise == s2) return true;
        
        return false;
    }
};

int main(){
    Solution s;
    string a = "amazon";
    string b = "azonam";
    cout << s.isRotated(a, b) << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Brute force approach TC : O(n^2)
        // vector<int> ans;
        // for(int i=0; i<numbers.size(); i++){
        //     for(int j=i+1; j<numbers.size(); j++){
        //         if(numbers[i] + numbers[j] == target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //             return ans;
        //         }
        //     }
        // }
        // return ans;

        // Optimal : 2 Pointers approach TC : O(n)
        vector<int> ans;
        int lp=0, rp=numbers.size()-1;
        while(lp < rp){
            if(numbers[lp] + numbers[rp] == target){
                ans.push_back(lp+1);
                ans.push_back(rp+1);
                return ans;
            }
            if(numbers[lp] + numbers[rp] > target){
                rp--;
            }
            else{
                lp++;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr = {2,7,11,15};
    vector<int> res = s.twoSum(arr, 9);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << "\t";
    }
    cout << endl;
    return 0;
}
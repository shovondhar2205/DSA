#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force approach TC : O(n^2)
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }


    // Optimized approach TC : O(nlogn) but it will not submit
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int st = 0, end = nums.size()-1;
        while(st < end){
            if(nums[st] + nums[end] == target){
                ans.push_back(st);
                ans.push_back(end);
                return ans;
            }
            else if(nums[st] + nums[end] > target){
                end--;
            }
            else{
                st++;
            }
        }
        return ans;
    }


    // Using Hashing TC : O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int second = target - first;
            if(m.find(second) != m.end()){
                ans.push_back(i);
                ans.push_back(m[second]);
                return ans;
            }
            m[first] = i;
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2,7,11,15};
    vector<int> res = s.twoSum(arr, 13);
    for(int i=0; i< res.size(); i++){
        cout << res[i] <<"\t";
    }
    cout << endl;
    return 0;
}
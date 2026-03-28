#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // Brute Force approach TC : O(n^2)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }

        return count;
    }

    // Solved using prefixsum TC : O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixsum(n, 0);

        prefixsum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }

        unordered_map<int, int> m;
        for(int j=0; j<n; j++){
            if(prefixsum[j] == k) count++;

            int val = prefixsum[j] - k;
            if(m.find(val) != m.end()){
                count += m[val];
            }

            if(m.find(prefixsum[j]) == m.end()){
                m[prefixsum[j]] = 0;
            }
            m[prefixsum[j]]++;
        }

        return count;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3};
    cout << s.subarraySum(arr, 3) << endl;
    return 0;
}



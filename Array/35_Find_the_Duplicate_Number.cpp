#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    // Using unordered set TC : O(n), SC : O(n)
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int val : nums){
            if(s.find(val) != s.end()){
                return val;
            }
            s.insert(val);
        }
        return -1;
    }

    // Using Slow Fast pointer TC : O(n), SC : O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do{
            slow = nums[slow];  // +1
            fast = nums[nums[fast]]; // +2
        }while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,4,2,2};
    cout << s.findDuplicate(nums) << endl;
    return 0;
}

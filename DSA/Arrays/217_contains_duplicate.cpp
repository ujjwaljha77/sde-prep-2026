 
//  LC , 217. Contains Duplicate: 

//  brute force: sort the array and check for adjacent elements, if they are same then return true, else return false at the end.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};

// optimized approach: use an unordered_map
// to store frequency of elements.
// if frequency of any element becomes greater than 1,
// then duplicate exists.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for (int i : nums) {
            m[i]++;
        }

        for (auto it : m) {
            if(it.second > 1) {
                return true;
            }
        }
        return false;
    }
};

// Lc, 1. Two Sum

// brute force approach: use two nested loops to check for all pairs of elements in the array, if we find a pair that is equal to the target, then return the indices of the two elements, else return an empty vector at the end.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

         for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
         }
        return {};
    }
};

// optimized approach: use an unordered_map
// to store elements and their indices.
// if target - current element already exists in the map,
// return their indices.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {

            int ans = target - nums[i];

            if(m.count(ans)) {
                return {m[ans], i};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};




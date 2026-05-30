class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++) {

            int left = i + 1;
            int right = nums.size()-1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {

                    ans.insert({nums[i], nums[left], nums[right]});

                    left++;
                    right--;
                }

                else if(sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};



// yaha humne 3 sum problem solve kiya hai
// yaha humne 2 pointer technique use kiya hai
// pahley humne array ko sort kar diya hai
// fir humne ek set banaya hai jisme hum unique triplets store karenge
// fir humne ek loop chalaya hai jisme humne left pointer ko i+1 se start kiya hai aur right pointer ko last index se start kiya hai
// fir humne sum calculate kiya hai agar sum 0 hai to humne triplet
// ko set me insert kar diya hai aur left pointer ko aage badha diya hai aur right pointer ko peeche le aaya hai
// agar sum 0 se chota hai to humne left pointer ko aage badha
// agar sum 0 se bada hai to humne right pointer ko peeche le aaya hai
// last me humne set ko vector me convert kar diya hai aur return kar diya hai
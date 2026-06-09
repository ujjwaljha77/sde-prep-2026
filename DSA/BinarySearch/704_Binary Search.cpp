class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high= nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            // int mid = (low + high) / 2;    // can cause integer overflow

            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] > target ){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return -1;
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)
// yaha humne low aur high ke liye do pointer use kiye hain, jisse hum array ke beech mein se start karte hain aur target element ko dhundte hain. Har iteration mein hum mid element ko check karte hain, agar mid element target ke barabar hai to hum mid index return kar dete hain. Agar mid element target se bada hai to hum high pointer ko mid - 1 kar dete hain, aur agar mid element target se chhota hai to hum low pointer ko mid + 1 kar dete hain. Is tarah se hum binary search algorithm ka use karke target element ko efficiently dhund sakte hain.
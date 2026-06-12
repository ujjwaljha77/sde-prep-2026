class Solution {
public:
    int findMin(vector<int>& nums) {


        // sort(nums.begin(), nums.end());
        // return nums[0];     // o(n logn)


        // int mini = INT_MAX;
        // for(int i = 0; i < nums.size(); i++) {
        //     if (nums[i] < mini) {
        //         mini = nums[i];
        //     }
        // }
        // return mini;      // o(n);

        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high) {
            
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return nums[low];   // o(logn)
    }
};


// Time Complexity: O(log n)
// Space Complexity: O(1)
// yaha humne low aur high ke liye do pointer use kiye hain, j
// jisse hum array ke beech mein se start karte hain aur minimum element ko dhundte hain. Har iteration mein hum mid element ko check karte hain, agar mid element high element se bada hai to hum low pointer ko mid + 1 kar dete hain, aur agar mid element high element se chhota ya barabar hai to hum high pointer ko mid kar dete hain. Is tarah se hum binary search algorithm ka use karke minimum element ko efficiently dhund sakte hain. Jab low pointer high pointer ke barabar ho jata hai to low pointer hi minimum element ka index hota hai, isliye hum nums[low] return kar dete hain.
// yaha humne mid index calculate karne ke liye low + (high - low) / 2 ka use kiya hai, jisse integer overflow se bach sakte hain. Agar hum (low + high) / 2 ka use karte hain to low aur high ke values bahut bade hone par integer overflow ho sakta hai, lekin low + (high - low) / 2 mein aisa nahi hota hai. Is tarah se hum binary search algorithm ka use karke minimum element ko efficiently dhund sakte hain.

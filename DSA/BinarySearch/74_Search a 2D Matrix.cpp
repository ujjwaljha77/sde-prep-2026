class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low =0;
        int high = (m * n) - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {
                return true;
            }else if(matrix[row][col] > target){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return false;
    }
};

// Time Complexity: O(log (m*n)) => O(log m + log n) => O(log m) + O(log n) => O(log m) + O(log n) => O(log m + log n)
// Space Complexity: O(1)
// yaha humne low aur high ke liye do pointer use kiye hain, jisse hum matrix ke beech mein se start karte hain aur target element ko dhundte hain. Har iteration mein hum mid element ko check karte hain, agar mid element target ke barabar hai to hum true return kar dete hain. Agar mid element target se bada hai to hum high pointer ko mid - 1 kar dete hain, aur agar mid element target se chhota hai to hum low pointer ko mid + 1 kar dete hain. Is tarah se hum binary search algorithm ka use karke target element ko efficiently dhund sakte hain.
// Yaha humne matrix ke elements ko ek single array ke tarah treat kiya hai, jisme hum mid index se row aur column calculate karte hain. Row calculate karne ke liye hum mid index ko n (number of columns) se divide karte hain, aur column calculate karne ke liye hum mid index ko n se modulus karte hain. Is tarah se hum binary search algorithm ka use karke target element ko efficiently dhund sakte hain.
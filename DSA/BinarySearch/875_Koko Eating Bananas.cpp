class Solution {
public:

    bool canEat(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for(int pile : piles) {
            hours += (pile + speed - 1) / speed;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canEat(piles, h, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};


// Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile.
// Space Complexity: O(1)
// yaha humne low aur high ke liye do pointer use kiye hain, jisse hum eating speed ke range mein se start karte hain aur minimum eating speed ko dhundte hain. Har iteration mein hum mid eating speed ko check karte hain, agar mid eating speed se Koko sabhi piles ko h hours mein kha sakta hai to hum high pointer ko mid - 1 kar dete hain, aur agar mid eating speed se Koko sabhi piles ko h hours mein nahi kha sakta hai to hum low pointer ko mid + 1 kar dete hain. Is tarah se hum binary search algorithm ka use karke minimum eating speed ko efficiently dhund sakte hain.
// yaha humne canEat function ka use kiya hai, jisme hum har pile
// ke liye hours calculate karte hain, jisme hum pile ko speed se divide karte hain aur agar pile speed se perfectly divide nahi hota hai to hum hours ko 1 se increment kar dete hain. Is tarah se hum total hours calculate karte hain, aur agar total hours h se kam ya barabar hai to hum true return kar dete hain, otherwise false return kar dete hain. Is tarah se hum binary search algorithm ka use karke minimum eating speed ko efficiently dhund sakte hain.
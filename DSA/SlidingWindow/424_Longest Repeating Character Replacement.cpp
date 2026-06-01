class Solution {
public:

    int characterReplacement(string s, int k) {

        unordered_map<char,int> m;

        int left = 0;

        int maxFreq = 0;

        int maa = 0;

        for(int right = 0; right < s.size(); right++) {

            m[s[right]]++;

            maxFreq = max(maxFreq, m[s[right]]);

            while((right - left + 1) - maxFreq > k) {

                m[s[left]]--;

                left++;
            }

            maa = max(maa, right - left + 1);
        }

        return maa;
    }
};

// Time Complexity: O(n) where n is the length of the string s
// Space Complexity: O(1) since the character set is fixed (26 uppercase English letters)
// yaha mainey sliding window technique ka use kiya hai jisme mainey ek unordered_map banaya hai jisme mainey current window ke characters ki frequency ko store kiya hai. Jab bhi right pointer se koi character add hota hai, toh main uski frequency ko update karta hoon aur maximum frequency ko bhi update karta hoon. Agar current window ka size minus maximum frequency greater than k hota hai, toh main left pointer ko move karta hoon aur us character ki frequency ko decrease karta hoon. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
// unordered_map ka use kiya hai kyuki humein characters ki frequency ko store kar
// na hai, aur isse hum O(1) time mein update kar sakte hain. Jab bhi right pointer se koi character add hota hai, toh main uski frequency ko update karta hoon aur maximum frequency ko bhi update karta hoon. Agar current window ka size minus maximum frequency greater than k hota hai, toh main left pointer ko move karta hoon aur us character ki frequency ko decrease karta hoon. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
// abb hum jo hai code likha hai usme humne ek unordered_map banaya hai
// jisme hum current window ke characters ki frequency ko store karte hain. Jab bhi right pointer se koi character add hota hai, toh main uski frequency ko update karta hoon aur maximum frequency ko bhi update karta hoon. Agar current window ka size minus maximum frequency greater than k hota hai, toh main left pointer ko move karta hoon aur us character ki frequency ko decrease karta hoon. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
// abb akk window banega string ke characters ka, toh hum usme se left character ko remove karenge aur right character ko add karenge, aur phir check karenge ki kya current window ka size minus maximum frequency greater than k hai. Agar hai, toh hum left pointer ko move karenge aur us character ki frequency ko decrease karenge. Har step par hum maximum length ko update karenge. Jab loop khatam ho jata hai, toh main maximum length return karenge.
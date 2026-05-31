class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>a;

        int left = 0, maa = 0;

        for(int right = 0; right < s.size(); right++) {
            while(a.count(s[right])) {
                a.erase(s[left]);
                left++;
            }

            a.insert(s[right]);

            maa = max(maa, right - left + 1);
        }

        return maa;
    }
};

// Time Complexity: O(n) where n is the length of the string s
// Space Complexity: O(min(m, n)) where m is the size of the character set

// yaha mainey sliding window technique ka use kiya hai jisme mainey ek unordered_set banaya hai jisme mainey current window ke characters ko store kiya hai. Jab bhi right pointer se koi character repeat hota hai, toh main left pointer ko move karta hoon aur set se characters ko remove karta hoon jab tak repeat character remove nahi ho jata. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
// unordered_set ka use kiya hai kyuki humein unique characters chahiye, aur isse hum O(1) time mein check kar sakte hain ki koi character set mein hai ya nahi. Jab bhi right pointer se koi character repeat hota hai, toh main left pointer ko move karta hoon aur set se characters ko remove karta hoon jab tak repeat character remove nahi ho jata. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
// abb hum jo hai code likha hai usme humne ek unordered_set banaya hai jisme hum current window ke characters ko store karte hain. Jab bhi right pointer se koi character repeat hota hai, toh main left pointer ko move karta hoon aur set se characters ko remove karta hoon jab tak repeat character remove nahi ho jata. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
// abb akk window banega string ke characters ka, toh hum usme se left character ko remove karenge aur right character ko add karenge, aur phir check karenge ki kya right character repeat ho raha hai. Agar ho raha hai, toh hum left pointer ko move karenge aur set se characters ko remove karenge jab tak repeat character remove nahi ho jata. Har step par hum maximum length ko update karenge. Jab loop khatam ho jata hai, toh main maximum length return karenge.
// yaha mainey sliding window technique ka use kiya hai jisme mainey ek unordered_set banaya hai jisme mainey current window ke characters ko store kiya hai. Jab bhi right pointer se koi character repeat hota hai, toh main left pointer ko move karta hoon aur set se characters ko remove karta hoon jab tak repeat character remove nahi ho jata. Har step par main maximum length ko update karta hoon. Jab loop khatam ho jata hai, toh main maximum length return karta hoon.
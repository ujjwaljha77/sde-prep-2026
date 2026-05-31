class Solution {
public:

    bool checkInclusion(string s1, string s2) {

        unordered_map<char,int> m1, m2;

        for(char c : s1) {
            m1[c]++;
        }

        int k = s1.size();
        if(s1.size() > s2.si ze()) {
            return false;
        }

        for(int i = 0; i < k; i++) {
            m2[s2[i]]++;
        }

        if(m1 == m2) {
            return true;
        }

        int left = 0;

        for(int right = k; right < s2.size(); right++) {

            m2[s2[right]]++;

            m2[s2[left]]--;

            if(m2[s2[left]] == 0) {
                m2.erase(s2[left]);
            }

            left++;

            if(m1 == m2) {
                return true;
            }
        }

        return false;
    }
};

// Time Complexity: O(n) where n is the length of s2
// Space Complexity: O(1) since the size of the hash maps will be at most 26 (number of lowercase letters)
// yaha mainey sliding window technique ka use kiya hai jisme mainey s1 ke characters ko count kiya hai aur phir s2 ke characters ko count karte hue window ko slide kiya hai. Har step par mainey check kiya hai ki kya dono hash maps equal hain, agar hain to return true. Agar loop khatam ho jata hai to return false.
// or unordered_map ke comparison operator ko use kiya hai kyuki isey hum directly compare kar sakte hain, agar dono maps ke key-value pairs same hain to woh equal honge.
// abb hum jo hai code likha hai usme humne pehle s1 ke characters ko count kiya hai aur phir s2 ke characters ko count karte hue window ko slide kiya hai. Har step par hum check karte hain ki kya dono hash maps equal hain, agar hain to return true. Agar loop khatam ho jata hai to return false.
// abb akk window banega s2 ke characters ka, toh hum usme se left character ko remove karenge aur right character ko add karenge, aur phir check karenge ki kya dono hash maps equal hain. Agar hain to return true. Agar loop khatam ho jata hai to return false.

// brute force approach 

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) {
            return true;
        }
        
        return false;
    }
};




// optimised approach using unordered_map to count the frequency of characters in string s and then decrement the frequency for characters. in string t. Finally, check if all frequencies are zero, if not then return false.

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<char,int>m;
        for(auto i : s){
            m[i]++;
        }

        for(auto i : t) {
            m[i]--;
        }

        for(auto it : m ) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};

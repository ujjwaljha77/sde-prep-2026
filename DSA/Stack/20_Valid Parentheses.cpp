class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {

                if(st.empty()) {
                    return false;
                }

                if(s[i] == ')' && st.top() != '(') {
                    return false;
                }

                if(s[i] == ']' && st.top() != '[') {
                    return false;
                }

                if(s[i] == '}' && st.top() != '{') {
                    return false;
                }

                st.pop();
            }

        }

        
        return st.empty();
    }
};



// Time Complexity: O(n)  where n is the length of the string s
// Space Complexity: O(n)  in the worst case when all characters are opening brackets
// yaha mainey ek stack banaya hai jisme main opening brackets ko store karta hoon. Jab bhi main closing bracket encounter karta hoon, toh main check karta hoon ki kya stack empty hai. Agar hai, toh iska matlab hai ki koi matching opening bracket nahi hai, toh main false return karta hoon. Agar stack empty nahi hai, toh main check karta hoon ki kya current closing bracket ke corresponding opening bracket stack ke top par hai. Agar nahi hai, toh main false return karta hoon. Agar hai, toh main us opening bracket ko stack se pop kar deta hoon. Loop ke end mein, agar stack empty hai, toh iska matlab hai ki saare brackets properly closed hain, toh main true return karta hoon. Agar stack empty nahi hai, toh iska matlab hai ki kuch opening brackets ka matching closing bracket nahi hai, toh main false return karta hoon.
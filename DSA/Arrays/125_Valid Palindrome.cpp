class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right) {
           if(!isalnum(s[left])) {
                left++;
            }else if(!isalnum(s[right])) {
                right--;
            }else if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }else {
                left++;
                right--;
            }
            
        }
        return true;
    }
};


// hamney 2 pointer technique use kiya pahley do pointer ley liyey left right left index 0 sey or right index last sey chalu hoga 
// abb hadekngey ki koi bhi letter agar alphanumeric nahi hai yani alphabetic ya numeric nahi hai jaisey abcd.... to usko skip karo agar nahi special char hai to usko skip karo or agey badho left++ yaa right-- karo 
// abb jo hai palindrome chack karngey jaisey phaley to lower mai sab ko convert karngey abb chck karngey first or last same hai to agey badha nahi hai to agey padney ki jarurat nahi siddha false return karo or hai to agey badh kar left age jaoo right sey phichey phir while check hoga or phir wahi process agar pura same hai to true return hojaega last mai
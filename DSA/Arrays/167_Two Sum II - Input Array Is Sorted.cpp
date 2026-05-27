class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while(left < right) {
            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left+1, right+1};
            }else if(sum > target) {
                right--;
            }else{
                left++;
            }

        }

        return {};
    }
};


// 2 pointer liya left right left index 0 sey or right index last sey chalu hoga
// abb hadekngey ki sum target ke barabar hai to return kar do left+1 or right+1 kyuki question mai 1 based index chahiye
// abb agar sum target se bada hai to right pointer ko left ki taraf le aao right-- karo
// abb agar sum target se chota hai to left pointer ko right ki taraf le aao left++ karo
// abb jab tak left pointer right pointer se chota hai tab tak loop chalega   
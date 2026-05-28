class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right = height.size()-1;
        int ans = 0, maa = 0;
        while(left < right){
            int mini = min(height[left], height[right]);
            ans = mini * (right-left);
            maa = max(maa, ans);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }

        return maa;
    }
};

yaha humne 2 pointer technique use kiya hai left right left index 0 sey or right index last sey chalu hoga
abb ham dekngey ki height[left] height[right] se chota hai to left pointer ko aage badha do left++ karo
abb ham dekngey ki height[right] height[left] se chota hai to right pointer ko peeche le aao right-- karo
abb ham dekngey ki height[left] height[right] ke barabar hai to left pointer ko aage badha do left++ karo or right pointer ko peeche le aao right-- karo
abb jab tak left pointer right pointer se chota hai tab tak loop chalega
class Solution {
public:
    int findMin(vector<int>& nums) {


        // sort(nums.begin(), nums.end());
        // return nums[0];     // o(n logn)


        // int mini = INT_MAX;
        // for(int i = 0; i < nums.size(); i++) {
        //     if (nums[i] < mini) {
        //         mini = nums[i];
        //     }
        // }
        // return mini;      // o(n);

        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high) {
            
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return nums[low];   // o(logn)
    }
};



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = nums[i];
            for(int j = i+1; j < nums.size(); j++){
                sum = sum + nums[j];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// solved and felt so good solved by my own brute force but got TLE 15 mins 
// explain: so what i am doing is i stored max value of the array because if two element -1,5 so ans must come five if loop runs according to loop it will only run till last second bause i used for(int i = 0; i < nums.size()-1; i++) { used because i am storing max elemnt in ans and if sum is not gretr than that elemnt why to iterate again 



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int ans = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
            }
            
        }

        return ans;
    }
};

// opyimes bhi kiya gpt hint key liyey like it explained me about kadane algo like why to take negative sum if we are not taking it we can removre one loop which can make complexity less
// Actual Kadane Intuition

// Har index pe do choices:

// 1. purana subarray continue karo agar posyive hai
// 2. naya subarray start karo agar negative hai kyuki purana subarray useless hai



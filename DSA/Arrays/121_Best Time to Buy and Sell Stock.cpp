// brute force approach:
// this may give TLE for large inputs because if n=10000
// time complexity is O(n^2)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long maa = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            for(int j = i+1; j < prices.size(); j++) {
                if(prices[i] < prices[j]){
                    long long profit = prices[j] - prices[i];
                    maa = max(maa, profit);

                }

            }
        }
        return maa;
    }
};


// optimised approach is to keep track of the minimum price and calculate the profit at each step and update the maximum profit accordingly. This approach has a time complexity of O(n) and space complexity of O(1).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnn = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size() ; i++){
            if(prices[i] < mnn) {
                mnn = prices[i];
            }

            profit  = max(profit, prices[i]-mnn);
        }

        return profit;
    }
};
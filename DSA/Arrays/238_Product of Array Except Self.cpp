class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pro = 1;
        vector<int>arr;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(j != i) {
                    pro *= nums[j]; 

                }
            }
            arr.push_back(pro);
            pro = 1;
        }

        return arr;
    }
};

// brute force 14 mins total time took 
// i was thinking of the optimised one so that i can code it in 0(n) but got error so then tried brute force

// here what i have done is i am storing the product in pro and pushing that pro in new vector array when i and j is not eqal to avoid self 


// optimised one: took ai help and done in 17 mins first 15min tried own then went on ai again did in 2min on own

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1]; 
        }

        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++) {
            arr[i] = suffix[i] * prefix[i];
        }

        return arr;
    }
};



// yaha hum akk kaam kartey hai jo no. hai uska left ka product nikaltey hai or next mai right ka abb akri mai left ka product or right key
// yaha hum 3 arrays use kar rahe hain:
//
// 1. prefix array
// prefix[i] = left side ka product
//
// 2. suffix array
// suffix[i] = right side ka product
//
// then final answer:
//
// arr[i] = prefix[i] * suffix[i]
//
// because current element ko include nahi karna.
//
// Example:
//
// nums = [1,2,3,4]
//
// prefix:
// [1,1,2,6]
//
// suffix:
// [24,12,4,1]
//
// final:
//
// [24,12,8,6]
//
// har index par:
// left side product * right side product
//
// isliye current element automatically exclude ho jata hai. product ka product kartey hai or return kartey hai 

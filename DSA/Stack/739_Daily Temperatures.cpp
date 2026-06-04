class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  temperatures[i] > temperatures[st.top()]) {

                int idx = st.top();
                st.pop();

                ans[idx] = i - idx;
            }

            st.push(i);
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Where n is the size of the input array temperatures.
// This code uses a stack to keep track of the indices of the temperatures.
// For each temperature, it pops from the stack until it finds a temperature that is greater than
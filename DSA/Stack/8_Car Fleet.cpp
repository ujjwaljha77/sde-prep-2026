class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int,int>> cars;
        for(int i = 0 ; i < n; i++) {
            cars.push_back({position[i], speed[i]});

        }
        sort(cars.begin(), cars.end());

        // int fleet = 0;
        // double req = 0;

        stack<double> st;

        for(int i = n - 1; i >= 0; i--) {

            double time = (double)(target - cars[i].first) / cars[i].second;

            // if(time > req) {
            //     fleet++;
            //     req = time;
            // }

            if(st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        // return fleet;
        return st.size();
        
    }
};

// Time Complexity: O(n log n)  where n is the number of cars, due to sorting the cars based on their positions.
// Space Complexity: O(n)  in the worst case when all cars form a single fleet, we need to store the time taken for each car in the stack. In the best case, when all cars form separate fleets, the space complexity is O(1) as we only need to store one time value at a time.
// yaha mainey pehle cars ke position aur speed ko ek vector of pairs mein store kiya hai. Fir mainey is vector ko position ke hisaab se sort kiya hai. Uske baad mainey stack ka use karke time calculate kiya hai ki har car target tak pahunchne mein kitna time legi. Agar current car ka time stack ke top se zyada hai, toh iska matlab hai ki current car ek nayi fleet banayegi, toh main us time ko stack mein push kar deta hoon. Loop ke end mein, stack mein jitne bhi time values hain, unka count hi total fleets ka count hoga, toh main stack ka size return karta hoon.
// Is approach se hum efficiently calculate kar sakte hain ki kitni car fleets target tak pahunchengi, aur iska time complexity O(n log n) hai due to sorting, aur space complexity O(n) hai in the worst case.
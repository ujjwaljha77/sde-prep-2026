class MinStack {
public:

    stack<int>st;
    stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == minSt.top())
        {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // Time Complexity: O(1) for all operations (push, pop, top, getMin)
    // Space Complexity: O(n) in the worst case, where n is the number of elements in the stack (if all elements are the same and are pushed onto the minSt)
// yaha mainey do stack banaya hai, ek st jisme main saare elements ko store karta hoon, aur ek minSt jisme main minimum elements ko store karta hoon. Jab bhi main push karta hoon, toh main check karta hoon ki kya current value minimum stack ke top se chhoti ya barabar hai. Agar hai, toh main usse minimum stack mein push kar deta hoon. Jab main pop karta hoon, toh main check karta hoon ki kya current top element minimum stack ke top ke barabar hai. Agar hai, toh main usse minimum stack se bhi pop kar deta hoon. Top function simply st ke top element ko return karta hai, aur getMin function minimum stack ke top element ko return karta hai. Is tarah se hum O(1) time complexity mein minimum element ko track kar sakte hain.
// 
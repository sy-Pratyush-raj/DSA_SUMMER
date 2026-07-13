//             Insert an Element at the Bottom of a Stack


class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        
        // base case
        
        if(st.empty()){
            st.push(x);
            return st;
        }
        
        int topVal = st.top();
        st.pop();
        st = insertAtBottom(st, x);
        st.push(topVal);
        
        return st;
    }
};
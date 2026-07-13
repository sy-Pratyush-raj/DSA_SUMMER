//                       Reverse first K of a Queue


class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {

        stack<int> st;
        int n = q.size();

        // Push first k elements into stack
        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }

        // Push them back into queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Move the remaining elements to the back
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

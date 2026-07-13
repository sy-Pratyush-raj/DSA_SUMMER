//             Insert an Element at the Bottom of a Stack


// class Solution {
//   public:
//     stack<int> insertAtBottom(stack<int> st, int x) {
        
//         // base case
        
//         if(st.empty()){
//             st.push(x);
//             return st;
//         }
        
//         int topVal = st.top();
//         st.pop();
//         st = insertAtBottom(st, x);
//         st.push(topVal);
        
//         return st;
//     }
// };

//                       Stack using Queue


// class myStack {
//     queue<int> q;

// public:

//     void push(int x) {
//         q.push(x);

//         int n = q.size();

//         for (int i = 0; i < n - 1; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         if (q.empty())
//             return -1;

//         int topVal = q.front();
//         q.pop();
//         return topVal;
//     }

//     int top() {
//         if (q.empty())
//             return -1;

//         return q.front();
//     }

//     int size() {
//         return q.size();
//     }
// };

//                         Queue Reversal


// #include <queue>
// #include <stack>
// using namespace std;

// class Solution {
//   public:
//     void reverseQueue(queue<int> &q) {
//         stack<int> s;

//         while(!q.empty()){
//             s.push(q.front());
//             q.pop();    
//         }

//         while(!s.empty()){
//             q.push(s.top());
//             s.pop();
//         }
//     }
// };



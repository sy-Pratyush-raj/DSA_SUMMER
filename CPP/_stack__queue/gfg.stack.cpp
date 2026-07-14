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


//      Interleave the First Half of the Queue with Second Half



// class Solution {
//   public:
//     void rearrangeQueue(queue<int> &q) {
        
//         stack<int> st;
//         int halfSize = q.size()/2;
        
//         // push the first half elements in stack
//         // queue : 16 17 18 19 20 || stack : 15 14 13 12 11
//         for(int i = 0; i < halfSize; i++){
//             st.push(q.front());
//             q.pop();
//         }
        
//         // enqueue back the stack elements in queue
//         // queue : 16 17 18 19 20 15 14 13 12 11
//         while(!st.empty()){
//             q.push(st.top());
//             st.pop();
//         }
        
//         // dequeue the first half elements of queue and enqueue them back
//         // queue : 15 14 13 12 11 16 17 18 19 20
//         for(int i = 0; i < halfSize; i++){
//             q.push(q.front());
//             q.pop();
//         }
        
//         // again push the first half elements in stack
//         // queue : 16 17 18 19 20 || stack : 11 12 13 14 15
//         for(int i = 0; i < halfSize; i++){
//             st.push(q.front());
//             q.pop();
//         }
        
//         // interleave the stack and queue elements
//         // stack : 11 12 13 14 15
//         // queue : 16 17 18 19 20
//         while(!st.empty()){
            
//             // push top element of stack
//             // queue : 16 17 18 19 20 11
//             q.push(st.top());
//             st.pop();
            
//             // push front element of queue
//             // queue : 17 18 19 20 11 16
//             q.push(q.front());
//             q.pop();
//         }
        
//         // final queue :
//         // 11 16 12 17 13 18 14 19 15 20
//     }
// };

//                    Next Greater 

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
        
        for(int i = n-1; i>=0 ; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] =-1;
            }else{
                nge[i] = st.top();
            }
            st.push(arr[i]);
        }
        return nge;
    }
};
